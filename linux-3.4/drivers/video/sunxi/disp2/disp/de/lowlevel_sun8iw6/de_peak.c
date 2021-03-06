
#include "de_peak_type.h"
#include "de_rtmx.h"
#include "de_enhance.h"

#define PEAK_OFST	0xA6000	

static volatile __peak_reg_t *peak_dev[DEVICE_NUM][CHN_NUM];
static de_reg_blocks peak_block[DEVICE_NUM][CHN_NUM];
static de_reg_blocks peak_gain_block[DEVICE_NUM][CHN_NUM];

int de_peak_set_reg_base(unsigned int sel, unsigned int chno, unsigned int base)
{
	__inf("sel=%d, chno=%d, base=0x%x\n", sel, chno, base);
	peak_dev[sel][chno] = (__peak_reg_t *)base;

	return 0;
}

int de_peak_update_regs(unsigned int sel, unsigned int chno)
{
	if(peak_block[sel][chno].dirty == 0x1){
		memcpy((void *)peak_block[sel][chno].off,peak_block[sel][chno].val,peak_block[sel][chno].size);
		peak_block[sel][chno].dirty = 0x0;}

	if(peak_gain_block[sel][chno].dirty == 0x1){
		memcpy((void *)peak_gain_block[sel][chno].off,peak_gain_block[sel][chno].val,peak_gain_block[sel][chno].size);
		peak_gain_block[sel][chno].dirty = 0x0;}


	return 0;
}

int de_peak_init(unsigned int sel, unsigned int chno, unsigned int reg_base)
{
	unsigned int base;
	void *memory;

	base = reg_base + (sel+1)*0x00100000 + PEAK_OFST;
	__inf("sel %d, peak_base[%d]=0x%x\n", sel, chno, base);

	memory = disp_sys_malloc(sizeof(__peak_reg_t));
	if(NULL == memory) {
		__wrn("malloc peak[%d][%d] memory fail! size=0x%x\n", sel, chno, sizeof(__peak_reg_t));
		return -1;
	}

	peak_block[sel][chno].off			= base;
	peak_block[sel][chno].val			= memory;
	peak_block[sel][chno].size			= 0x10;
	peak_block[sel][chno].dirty 		= 0;

	peak_gain_block[sel][chno].off		= base + 0x10;
	peak_gain_block[sel][chno].val		= memory + 0x10;
	peak_gain_block[sel][chno].size		= 0x20;
	peak_gain_block[sel][chno].dirty 	= 0;

	de_peak_set_reg_base(sel, chno, (unsigned int)memory);

	return 0;
}

int de_peak_enable(unsigned int sel, unsigned int chno, unsigned int en)
{
	__inf("sel=%d, chno=%d, en=%d\n", sel, chno, en);
	peak_dev[sel][chno]->ctrl.bits.en = en;
	peak_block[sel][chno].dirty 	=	1;
	return 0;
}

int de_peak_set_size(unsigned int sel, unsigned int chno, unsigned int width, unsigned int height)
{
	peak_dev[sel][chno]->size.bits.width = width - 1;
	peak_dev[sel][chno]->size.bits.height = height - 1;
	peak_block[sel][chno].dirty 	=	1;
	return 0;
}

int de_peak_set_window(unsigned int sel, unsigned int chno, unsigned int win_enable, de_rect window)
{
	peak_dev[sel][chno]->ctrl.bits.win_en = win_enable;

	if(win_enable)
	{
		peak_dev[sel][chno]->win0.bits.win_left = window.x;
		peak_dev[sel][chno]->win0.bits.win_top = window.y;
		peak_dev[sel][chno]->win1.bits.win_right = window.x + window.w - 1;
		peak_dev[sel][chno]->win1.bits.win_bot = window.y + window.h - 1;
	}
	peak_block[sel][chno].dirty 	=	1;
	return 0;
}

int de_peak_set_para(unsigned int sel, unsigned int chno, unsigned int gain, unsigned int hp_ratio,
						unsigned int bp0_ratio)
{
	peak_dev[sel][chno]->gain.bits.gain = gain;
	peak_dev[sel][chno]->filter.bits.filter_sel = 0;
	peak_dev[sel][chno]->filter.bits.hp_ratio = hp_ratio;
	peak_dev[sel][chno]->filter.bits.bp0_ratio = bp0_ratio;

	peak_dev[sel][chno]->filter.bits.bp1_ratio = 0;
	peak_dev[sel][chno]->gainctrl.bits.beta = 0;
	peak_dev[sel][chno]->gainctrl.bits.dif_up = 128;
	peak_dev[sel][chno]->shootctrl.bits.neg_gain = 31;
	peak_dev[sel][chno]->coring.bits.corthr = 4;

	peak_gain_block[sel][chno].dirty 	=	1;
	return 0;
}

int de_peak_info2para(unsigned int sharp, de_rect window, __peak_config_data *para)
{
	int mode;
	int peak_para[PEAK_PARA_NUM][PEAK_MODE_NUM] = {
	{0,36,48},//gain
	{0,0x4,0xe},//hp_ratio
	{0,0xc,0x2},//bp0_ratio
	};

	mode = (sharp>>4)&0xf;
	para->peak_en = mode?1:0;

	para->gain = peak_para[0][mode];
	para->hp_ratio = peak_para[1][mode];
	para->bp0_ratio = peak_para[2][mode];

	return 0;
}

