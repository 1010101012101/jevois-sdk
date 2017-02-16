/*
 * SH7786 PCI-Express controller definitions.
 *
 * Copyright (C) 2008, 2009 Renesas Technology Corp.
 * All rights reserved.
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 */
#ifndef __PCI_SH7786_H
#define __PCI_SH7786_H

/* PCIe bus-0(x4) on SH7786 */     
#define SH4A_PCIE_SPW_BASE  0xFE000000  /* spw config address for controller 0 */
#define SH4A_PCIE_SPW_BASE1 0xFE200000  /* spw config address for controller 1 (Rev1.14)*/
#define SH4A_PCIE_SPW_BASE2 0xFCC00000  /* spw config address for controller 2 (Rev1.171)*/
#define SH4A_PCIE_SPW_BASE_LEN  0x00080000

#define SH4A_PCI_CNFG_BASE  0xFE040000  /* pci config address for controller 0 */
#define SH4A_PCI_CNFG_BASE1 0xFE240000  /* pci config address for controller 1 (Rev1.14)*/
#define SH4A_PCI_CNFG_BASE2 0xFCC40000  /* pci config address for controller 2 (Rev1.171)*/
#define SH4A_PCI_CNFG_BASE_LEN  0x00040000

#define SH4A_PCIPIO_ADDR_OFFSET 0x000001c0  /* offset to pci config_address */
#define SH4A_PCIPIO_DATA_OFFSET 0x00000220  /* offset to pci config_data */

/*
 * for PEX8111(Max Payload Size=128B,PCIIO_SIZE=64K),
 * for other(Max Payload Size=4096B,PCIIO_SIZE=8M)
 */

/* PCI0: PCI memory target transfer 32-bit address translation value(Rev1.11T)*/
#define SH4A_PCIBMSTR_TRANSLATION 0x20000000

/*  SPVCR0    */
#define SH4A_PCIEVCR0   (0x000000)  /* R - 0x0000 0000 32 */
#define   BITS_TOP_MB (24)
#define   MASK_TOP_MB (0xff<<BITS_TOP_MB)
#define   BITS_BOT_MB (16)
#define   MASK_BOT_MB (0xff<<BITS_BOT_MB)
#define   BITS_VC_ID  (0)
#define   MASK_VC_ID  (0xffff<<BITS_VC_ID)

/*  SPVCR1    */
#define SH4A_PCIEVCR1   (0x000004)  /* R - 0x0000 0000 32*/
#define   BITS_BADOPC (5)   /* 5 BADOPC 0 R/W */
#define   MASK_BADOPC (1<<BITS_BADOPC)
#define   BITS_BADDEST  (4)   /*4 BADDEST 0 R/W  */
#define   MASK_BADDEST  (1<<BITS_BADDEST)
#define   BITS_UNSOLRESP  (3)   /* 3 UNSOLRESP 0 R/W  */
#define   MASK_UNSOLRESP  (1<<BITS_UNSOLRESP)
#define   BITS_ERRSNT (1)   /* 1 ERRSNT 0 */
#define   MASK_ERRSNT (1<<BITS_ERRSNT)
#define   BITS_ERRRCV (0)   /* 0 ERRRCV 0 */
#define   MASK_ERRRCV (1<<BITS_ERRRCV)

/*  PCIEENBLR  */
#define SH4A_PCIEENBLR    (0x000008)  /* R/W - 0x0000 0001 32 */

/*  PCIEECR   */
#define SH4A_PCIEECR    (0x00000C)  /* R/W - 0x0000 0000 32 */
#define   BITS_ENBL (0) /* 0 ENBL 0 R/W */
#define   MASK_ENBL (1<<BITS_ENBL)

/*  PCIEPAR   */
#define SH4A_PCIEPAR    (0x000010)  /* R/W - 0x0000 0000 32 */
#define   BITS_BN   (24)
#define   MASK_BN   (0xff<<BITS_BN)
#define   BITS_DN   (19)
#define   MASK_DN   (0x1f<<BITS_DN)
#define   BITS_FN   (16)
#define   MASK_FN   (0x7<<BITS_FN)
#define   BITS_EREGNO (8)
#define   MASK_EREGNO (0xff<<BITS_EREGNO)
#define   BITS_REGNO  (2)
#define   MASK_REGNO  (0x3f<<BITS_REGNO)

/*  PCIEPCTLR */
#define SH4A_PCIEPCTLR    (0x000018)  /* R/W - 0x0000 0000 32 */
#define   BITS_CCIE (31)  /*  31 CCIE */
#define   MASK_CCIE (1<<BITS_CCIE)
#define   BITS_TYPE (8)
#define   MASK_TYPE (1<<BITS_TYPE)
#define   BITS_C_VC (0)
#define   MASK_C_VC (1<<BITS_C_VC)

/*  PCIEPDR   */
#define SH4A_PCIEPDR    (0x000020)  /* R/W - 0x0000 0000 32 */
#define   BITS_PDR  (0)
#define   MASK_PDR  (0xffffffff<<BITS_PDR)

/*  PCIEMSGALR  */
#define SH4A_PCIEMSGALR   (0x000030)  /* R/W - 0x0000 0000 32 */
#define   BITS_MSGADRL  (0)
#define   MASK_MSGADRL  (0xffffffff<<BITS_MSGADRL)

/*  PCIEMSGAHR  */
#define SH4A_PCIEMSGAHR   (0x000034)  /* R/W - 0x0000 0000 32 */
#define   BITS_MSGADRH  (0)
#define   MASK_MSGADRH  (0xffffffff<<BITS_MSGADRH)

/*  PCIEMSGCTLR */
#define SH4A_PCIEMSGCTLR  (0x000038)  /* R/W - 0x0000 0000 32 */
#define   BITS_MSGIE  (31)
#define   MASK_MSGIE  (1<<BITS_MSGIE)
#define   BITS_MROUTE (16)
#define   MASK_MROUTE (0x7<<BITS_MROUTE)
#define   BITS_MCODE  (8)
#define   MASK_MCODE  (0xff<<BITS_MCODE)
#define   BITS_M_VC (0)
#define   MASK_M_VC (1<<BITS_M_VC)

/*  PCIEMSG   */
#define SH4A_PCIEMSG    (0x000040)  /* W - - 32 */
#define   BITS_MDATA  (0)
#define   MASK_MDATA  (0xffffffff<<BITS_MDATA)

/*  PCIEUNLOCKCR  */
#define SH4A_PCIEUNLOCKCR (0x000048)  /* R/W - 0x0000 0000 32 */

/*  PCIEIDR   */
#define SH4A_PCIEIDR    (0x000060)  /* R/W - 0x0101 1101 32 */

/*  PCIEDBGCTLR */
#define SH4A_PCIEDBGCTLR  (0x000100)  /* R/W - 0x0000 0000 32 */

/*  PCIEINTXR */
#define SH4A_PCIEINTXR    (0x004000)  /* R/W - 0x0000 0000 32 */

/*  PCIERMSGR */
#define SH4A_PCIERMSGR    (0x004010)  /* R/W - 0x0000 0000 32 */

/*  PCIERSTR  */
#define SH4A_PCIERSTR(x)  (0x008000 + ((x) * 0x4)) /* R/W - 0x0000 0000 32 */

/*  PCIESRSTR  */
#define SH4A_PCIESRSTR    (0x008040)  /* R/W - 0x0000 0000 32 */

/*  PCIEPHYCTLR */
#define SH4A_PCIEPHYCTLR  (0x010000)  /* R/W - 0x0000 0000 32 */
#define   BITS_CKE  (0)
#define   MASK_CKE  (1<<BITS_CKE)

/*  PCIERMSGIER */
#define SH4A_PCIERMSGIER  (0x004040)  /* R/W - 0x0000 0000 32 */

/*  PCIEPHYCTLR */
#define SH4A_PCIEPHYCTLR  (0x010000)  /* R/W - 0x0000 0000 32 */

/*  PCIEPHYADRR */
#define SH4A_PCIEPHYADRR  (0x010004)  /* R/W - 0x0000 0000 32 */
#define   BITS_ACK  (24)     
#define   MASK_ACK  (1<<BITS_ACK)  
#define   BITS_CMD  (16)     
#define   MASK_CMD  (0x03<<BITS_CMD) 
#define   BITS_LANE (8)
#define   MASK_LANE (0x0f<<BITS_LANE)
#define   BITS_ADR  (0)
#define   MASK_ADR  (0xff<<BITS_ADR)

/*  PCIEPHYDINR */             
#define SH4A_PCIEPHYDINR  (0x010008)  /* R/W - 0x0000 0000 32 */

/*  PCIEPHYDOUTR  */
#define SH4A_PCIEPHYDOUTR (0x01000C)  /* R/W - 0x0000 0000 32 */

/*  PCIEPHYSR */
#define SH4A_PCIEPHYSR    (0x010010)  /* R/W - 0x0000 0000 32 */ 

/*  PCIEPHYDATAR  */
#define SH4A_PCIEPHYDATAR (0x00008) /* R/W - 0xxxxx xxxx 32 */
#define   BITS_DATA (0)
#define   MASK_DATA (0xffffffff<<BITS_DATA)

/*  PCIETCTLR */
#define SH4A_PCIETCTLR    (0x020000)  /* R/W R/W 0x0000 0000 32 */
#define   BITS_CFINT  (0)
#define   MASK_CFINT  (1<<BITS_CFINT)

/*  PCIETSTR  */
#define SH4A_PCIETSTR   (0x020004)  /* R 0x0000 0000 32  */

/*  PCIEINTR  */
#define SH4A_PCIEINTR   (0x020008)  /* R/W R/W 0x0000 0000 32  */
#define   BITS_INT_RX_ERP     (31)
#define   MASK_INT_RX_ERP     (1<<BITS_INT_RX_ERP)
#define   BITS_INT_RX_VCX_Posted    (30)
#define   MASK_INT_RX_VCX_Posted    (1<<BITS_INT_RX_VCX_Posted)
#define   BITS_INT_RX_VCX_NonPosted (29)
#define   MASK_INT_RX_VCX_NonPosted (1<<BITS_INT_RX_VCX_NonPosted)
#define   BITS_INT_RX_VCX_CPL   (28)
#define   MASK_INT_RX_VCX_CPL   (1<<BITS_INT_RX_VCX_CPL)
#define   BITS_INT_TX_VCX_Posted    (26)
#define   MASK_INT_TX_VCX_Posted    (1<<BITS_INT_TX_VCX_Posted)
#define   BITS_INT_TX_VCX_NonPosted (25)
#define   MASK_INT_TX_VCX_NonPosted (1<<BITS_INT_TX_VCX_NonPosted)
#define   BITS_INT_TX_VCX_CPL   (24)
#define   MASK_INT_TX_VCX_CPL   (1<<BITS_INT_TX_VCX_CPL)
#define   BITS_INT_RX_VC0_Posted    (22)
#define   MASK_INT_RX_VC0_Posted    (1<<BITS_INT_RX_VC0_Posted)
#define   BITS_INT_RX_VC0_NonPosted (21)
#define   MASK_INT_RX_VC0_NonPosted (1<<BITS_INT_RX_VC0_NonPosted)
#define   BITS_INT_RX_VC0_CPL   (20)
#define   MASK_INT_RX_VC0_CPL   (1<<BITS_INT_RX_VC0_CPL)
#define   BITS_INT_TX_VC0_Posted    (18)
#define   MASK_INT_TX_VC0_Posted    (1<<BITS_INT_TX_VC0_Posted)
#define   BITS_INT_TX_VC0_NonPosted (17)
#define   MASK_INT_TX_VC0_NonPosted (1<<BITS_INT_TX_VC0_NonPosted)
#define   BITS_INT_TX_VC0_CPL   (16)
#define   MASK_INT_TX_VC0_CPL   (1<<BITS_INT_TX_VC0_CPL)
#define   BITS_INT_RX_CTRL    (15)
#define   MASK_INT_RX_CTRL    (1<<BITS_INT_RX_CTRL)
#define   BITS_INT_TX_CTRL    (14)
#define   MASK_INT_TX_CTRL    (1<<BITS_INT_TX_CTRL)
#define   BITS_INTTL      (11)
#define   MASK_INTTL      (1<<BITS_INTTL)
#define   BITS_INTDL      (10)
#define   MASK_INTDL      (1<<BITS_INTDL)
#define   BITS_INTMAC     (9)
#define   MASK_INTMAC     (1<<BITS_INTMAC)
#define   BITS_INTPM      (8)
#define   MASK_INTPM      (1<<BITS_INTPM)

/*  PCIEINTER */
#define SH4A_PCIEINTER    (0x02000C)  /* R/W R/W 0x0000 0000 32 */
#define   BITS_INT_RX_ERP     (31)
#define   MASK_INT_RX_ERP     (1<<BITS_INT_RX_ERP)
#define   BITS_INT_RX_VCX_Posted    (30)
#define   MASK_INT_RX_VCX_Posted    (1<<BITS_INT_RX_VCX_Posted)
#define   BITS_INT_RX_VCX_NonPosted (29)
#define   MASK_INT_RX_VCX_NonPosted (1<<BITS_INT_RX_VCX_NonPosted)
#define   BITS_INT_RX_VCX_CPL   (28)
#define   MASK_INT_RX_VCX_CPL   (1<<BITS_INT_RX_VCX_CPL)
#define   BITS_INT_TX_VCX_Posted    (26)
#define   MASK_INT_TX_VCX_Posted    (1<<BITS_INT_TX_VCX_Posted)
#define   BITS_INT_TX_VCX_NonPosted (25)
#define   MASK_INT_TX_VCX_NonPosted (1<<BITS_INT_TX_VCX_NonPosted)
#define   BITS_INT_TX_VCX_CPL   (24)
#define   MASK_INT_TX_VCX_CPL   (1<<BITS_INT_TX_VCX_CPL)
#define   BITS_INT_RX_VC0_Posted    (22)
#define   MASK_INT_RX_VC0_Posted    (1<<BITS_INT_RX_VC0_Posted)
#define   BITS_INT_RX_VC0_NonPosted (21)
#define   MASK_INT_RX_VC0_NonPosted (1<<BITS_INT_RX_VC0_NonPosted)
#define   BITS_INT_RX_VC0_CPL   (20)
#define   MASK_INT_RX_VC0_CPL   (1<<BITS_INT_RX_VC0_CPL)
#define   BITS_INT_TX_VC0_Posted    (18)
#define   MASK_INT_TX_VC0_Posted    (1<<BITS_INT_TX_VC0_Posted)
#define   BITS_INT_TX_VC0_NonPosted (17)
#define   MASK_INT_TX_VC0_NonPosted (1<<BITS_INT_TX_VC0_NonPosted)
#define   BITS_INT_TX_VC0_CPL   (16)
#define   MASK_INT_TX_VC0_CPL   (1<<BITS_INT_TX_VC0_CPL)
#define   BITS_INT_RX_CTRL    (15)
#define   MASK_INT_RX_CTRL    (1<<BITS_INT_RX_CTRL)
#define   BITS_INT_TX_CTRL    (14)
#define   MASK_INT_TX_CTRL    (1<<BITS_INT_TX_CTRL)
#define   BITS_INTTL      (11)
#define   MASK_INTTL      (1<<BITS_INTTL)
#define   BITS_INTDL      (10)
#define   MASK_INTDL      (1<<BITS_INTDL)
#define   BITS_INTMAC     (9)
#define   MASK_INTMAC     (1<<BITS_INTMAC)
#define   BITS_INTPM      (8)
#define   MASK_INTPM      (1<<BITS_INTPM)

/*  PCIEEH0R  */
#define SH4A_PCIEEHR(x)   (0x020010 + ((x) * 0x4)) /* R - 0x0000 0000 32 */

/*  PCIEAIR  */
#define SH4A_PCIEAIR    (SH4A_PCIE_BASE + 0x020010) /* R/W R/W 0xxxxx xxxx 32 */

/*   PCIECIR   */
#define SH4A_PCIECIR    (SH4A_PCIE_BASE)  /* R/W R/W 0xxxxx xxxx 32 */

/*   PCIEERRFR   */              
#define SH4A_PCIEERRFR    (0x020020)    /* R/W R/W 0xxxxx xxxx 32 */ 

/*  PCIEERRFER  */
#define SH4A_PCIEERRFER   (0x020024)    /* R/W R/W 0x0000 0000 32 */

/*  PCIEERRFR2  */
#define SH4A_PCIEERRFR2   (0x020028)    /* R/W R/W 0x0000 0000 32 */

/*  PCIEMSIR  */
#define SH4A_PCIEMSIR   (0x020040)    /* R/W - 0x0000 0000 32 */

/*  PCIEMSIFR */
#define SH4A_PCIEMSIFR    (0x020044)    /* R/W R/W 0x0000 0000 32 */

/*  PCIEPWRCTLR */
#define SH4A_PCIEPWRCTLR  (0x020100)    /* R/W - 0x0000 0000 32 */

/*  PCIEPCCTLR  */
#define SH4A_PCIEPCCTLR   (0x020180)    /* R/W - 0x0000 0000 32 */

/*  PCIELAR0  */
#define SH4A_PCIELAR0   (0x020200)  /* R/W R/W 0x0000 0000 32 */
#define   BITS_LARn (20)
#define   MASK_LARn (0xfff<<BITS_LARn)

#define SH4A_PCIE_020204  (0x020204)  /* R/W R/W 0x0000 0000 32 */

/*  PCIELAMR0 */
#define SH4A_PCIELAMR0    (0x020208)  /* R/W R/W 0x0000 0000 32 */
#define   BITS_LAMRn  (20)
#define   MASK_LAMRn  (0x1ff<<BITS_LAMRn)
#define   BITS_LAREn  (0)
#define   MASK_LAREn  (0x1<<BITS_LAREn)

/*  PCIECSCR0 */
#define SH4A_PCIECSCR0    (0x020210)  /* R/W R/W 0x0000 0000 32 */
#define   BITS_RANGE  (2)
#define   MASK_RANGE  (0x7<<BITS_RANGE)
#define   BITS_SNPMD  (0)
#define   MASK_SNPMD  (0x3<<BITS_SNPMD)

/*  PCIECSAR0 */
#define SH4A_PCIECSAR0    (0x020214)  /* R/W R/W 0x0000 0000 32 */
#define   BITS_CSADR  (0)
#define   MASK_CSADR  (0xffffffff<<BITS_CSADR)

/*  PCIESTCTLR0 */
#define SH4A_PCIESTCTLR0  (0x020218)  /* R/W R/W 0x0000 0000 32 */
#define   BITS_SHPRI  (8)
#define   MASK_SHPRI  (0x0f<<BITS_SHPRI)

#define SH4A_PCIE_020224  (0x020224)  /* R/W R/W 0x0000 0000 32 */

#define SH4A_PCIELAR1   (0x020220)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIELAMR1    (0x020228)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSCR1    (0x020230)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSAR1    (0x020234)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIESTCTLR1  (0x020238)  /* R/W R/W 0x0000 0000 32 */

#define SH4A_PCIELAR2   (0x020240)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIE_020244  (0x020244)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIELAMR2    (0x020248)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSCR2    (0x020250)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSAR2    (0x020254)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIESTCTLR2  (0x020258)  /* R/W R/W 0x0000 0000 32 */

#define SH4A_PCIELAR3   (0x020260)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIE_020264  (0x020264)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIELAMR3    (0x020268)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSCR3    (0x020270)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSAR3    (0x020274)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIESTCTLR3  (0x020278)  /* R/W R/W 0x0000 0000 32 */

#define SH4A_PCIELAR4   (0x020280)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIE_020284  (0x020284)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIELAMR4    (0x020288)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSCR4    (0x020290)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSAR4    (0x020294)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIESTCTLR4  (0x020298)  /* R/W R/W 0x0000 0000 32 */

#define SH4A_PCIELAR5   (0x0202A0)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIE_0202A4  (0x0202A4)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIELAMR5    (0x0202A8)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSCR5    (0x0202B0)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIECSAR5    (0x0202B4)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIESTCTLR5  (0x0202B8)  /* R/W R/W 0x0000 0000 32 */

/*  PCIEPARL  */
#define SH4A_PCIEPARL(x)  (0x020400 + ((x) * 0x20)) /* R/W R/W 0x0000 0000 32 */
#define   BITS_PAL  (18)
#define   MASK_PAL  (0x3fff<<BITS_PAL)

/*  PCIEPARH  */
#define SH4A_PCIEPARH(x)  (0x020404 + ((x) * 0x20)) /* R/W R/W 0x0000 0000 32 */
#define   BITS_PAH  (0)
#define   MASK_PAH  (0xffffffff<<BITS_PAH)

/*  PCIEPAMR   */
#define SH4A_PCIEPAMR(x)  (0x020408 + ((x) * 0x20)) /* R/W R/W 0x0000 0000 32 */
#define   BITS_PAM  (18)
#define   MASK_PAM  (0x3fff<<BITS_PAM)

/*  PCIEPTCTLR  */
#define SH4A_PCIEPTCTLR(x)  (0x02040C + ((x) * 0x20))
#define   BITS_PARE (31)
#define   MASK_PARE (0x1<<BITS_PARE)
#define   BITS_TC   (20)
#define   MASK_TC   (0x7<<BITS_TC)
#define   BITS_T_VC (16)
#define   MASK_T_VC (0x1<<BITS_T_VC)
#define   BITS_LOCK (12)
#define   MASK_LOCK (0x1<<BITS_LOCK)
#define   BITS_SPC  (8)
#define   MASK_SPC  (0x1<<BITS_SPC)

#define SH4A_PCIEDMAOR    (0x021000)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSAR0   (0x021100)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSAHR0  (0x021104)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMDAR0   (0x021108)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMDAHR0  (0x02110C)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMBCNTR0 (0x021110)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSBCNTR0  (0x021114)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSTRR0  (0x021118)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCCAR0  (0x02111C)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCCR0   (0x021120)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCC2R0  (0x021124)  /* R/W R/W 0x0000 0000 - */
#define SH4A_PCIEDMCCCR0  (0x021128)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCHSR0  (0x02112C)  /* R/W - 0x0000 0000 32 */
#define SH4A_PCIEDMSAR1   (0x021140)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSAHR1  (0x021144)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMDAR1   (0x021148)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMDAHR1  (0x02114C)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMBCNTR1 (0x021150)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSBCNTR1  (0x021154)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSTRR1  (0x021158)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCCAR1  (0x02115C)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCCR1   (0x021160)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCC2R1  (0x021164)  /* R/W R/W 0x0000 0000 - */
#define SH4A_PCIEDMCCCR1  (0x021168)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCHSR1  (0x02116C)  /* R/W - 0x0000 0000 32 */
#define SH4A_PCIEDMSAR2   (0x021180)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSAHR2  (0x021184)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMDAR2   (0x021188)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMDAHR2  (0x02118C)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMBCNTR2 (0x021190)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSBCNTR2  (0x021194)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSTRR2  (0x021198)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCCAR2  (0x02119C)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCCR2   (0x0211A0)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCC2R2  (0x0211A4)  /* R/W R/W 0x0000 0000 -  */
#define SH4A_PCIEDMCCCR2  (0x0211A8)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSAR3   (0x0211C0)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSAHR3  (0x0211C4)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMDAR3   (0x0211C8)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMDAHR3  (0x0211CC)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMBCNTR3 (0x0211D0)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSBCNTR3  (0x0211D4)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMSTRR3  (0x0211D8)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCCAR3  (0x0211DC)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCCR3   (0x0211E0)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCC2R3  (0x0211E4)  /* R/W R/W 0x0000 0000 -  */
#define SH4A_PCIEDMCCCR3  (0x0211E8)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEDMCHSR3  (0x0211EC)  /* R/W R/W 0x0000 0000 32 */
#define SH4A_PCIEPCICONF0 (0x040000)  /* R R - 8/16/32 */
#define SH4A_PCIEPCICONF1 (0x040004)  /* R/W R/W 0x0008 0000 8/16/32 */
#define SH4A_PCIEPCICONF2 (0x040008)  /* R/W R/W 0xFF00 0000 8/16/32 */
#define SH4A_PCIEPCICONF3 (0x04000C)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEPCICONF4 (0x040010)  /* - R/W - 8/16/32 */
#define SH4A_PCIEPCICONF5 (0x040014)  /* - R/W - 8/16/32 */
#define SH4A_PCIEPCICONF6 (0x040018)  /* - R/W - 8/16/32 */
#define SH4A_PCIEPCICONF7 (0x04001C)  /* - R/W - 8/16/32 */
#define SH4A_PCIEPCICONF8 (0x040020)  /* - R/W - 8/16/32 */
#define SH4A_PCIEPCICONF9 (0x040024)  /* - R/W - 8/16/32 */
#define SH4A_PCIEPCICONF10  (0x040028)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEPCICONF11  (0x04002C)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEPCICONF12  (0x040030)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEPCICONF13  (0x040034)  /* R/W R/W 0x0000 0040 8/16/32 */
#define SH4A_PCIEPCICONF14  (0x040038)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEPCICONF15  (0x04003C)  /* R/W R/W 0x0000 00FF 8/16/32 */
#define SH4A_PCIEPMCAP0   (0x040040)  /* R/W R 0x0003 5001 8/16/32 */
#define SH4A_PCIEPMCAP1   (0x040044)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEMSICAP0  (0x040050)  /* R/W R/W 0x0180 7005 8/16/32 */
#define SH4A_PCIEMSICAP1  (0x040054)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEMSICAP2  (0x040058)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEMSICAP3  (0x04005C)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEMSICAP4  (0x040060)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEMSICAP5  (0x040064)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEEXPCAP0  (0x040070)  /* R/W R/W 0x0001 0010 8/16/32 */
#define SH4A_PCIEEXPCAP1  (0x040074)  /* R/W R 0x0000 0005 8/16/32 */
#define SH4A_PCIEEXPCAP2  (0x040078)  /* R/W R/W 0x0000 0801 8/16/32 */
#define SH4A_PCIEEXPCAP3  (0x04007C)  /* R/W R 0x0003 F421 8/16/32 */
#define SH4A_PCIEEXPCAP4  (0x040080)  /* R/W R/W 0x0041 0000 8/16/32 */
#define SH4A_PCIEEXPCAP5  (0x040084)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEEXPCAP6  (0x040088)  /* R/W R/W 0x0000 03C0 8/16/32 */
#define SH4A_PCIEEXPCAP7  (0x04008C)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEEXPCAP8  (0x040090)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEVCCAP0   (0x040100)  /* R/W R 0x1B01 0002 8/16/32 */
#define SH4A_PCIEVCCAP1   (0x040104)  /* R R 0x0000 0001 8/16/32 */
#define SH4A_PCIEVCCAP2   (0x040108)  /* R R 0x0000 0000 8/16/32 */
#define SH4A_PCIEVCCAP3   (0x04010C)  /* R R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEVCCAP4   (0x040110)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEVCCAP5   (0x040114)  /* R/W R/W 0x8000 00FF 8/16/32 */
#define SH4A_PCIEVCCAP6   (0x040118)  /* R/W R 0x0002 0000 8/16/32 */
#define SH4A_PCIEVCCAP7   (0x04011C)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEVCCAP8   (0x040120)  /* R/W R/W 0x0000 0000 8/16/32 */
#define SH4A_PCIEVCCAP9   (0x040124)  /* R/W R 0x0002 0000 8/16/32 */
#define SH4A_PCIENUMCAP0  (0x0001B0)  /* RW R 0x0001 0003 8/16/32 */
#define SH4A_PCIENUMCAP1  (0x0001B4)  /* R R 0x0000 0000 8/16/32 */
#define SH4A_PCIENUMCAP2  (0x0001B8)  /* R R 0x0000 0000 8/16/32 */
#define SH4A_PCIEIDSETR0  (0x041000)  /* R/W R 0x0000 FFFF 16/32 */
#define SH4A_PCIEIDSETR1  (0x041004)  /* R/W R 0xFF00 0000 16/32 */
#define SH4A_PCIEBAR0SETR (0x041008)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEBAR1SETR (0x04100C)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEBAR2SETR (0x041010)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEBAR3SETR (0x041014)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEBAR4SETR (0x041018)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEBAR5SETR (0x04101C)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIECISSETR  (0x041020)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEIDSETR2  (0x041024)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEEROMSETR (0x041028)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEDSERSETR0  (0x04102C)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEDSERSETR1  (0x041030)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIECTLR   (0x041040)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIETLSR   (0x041044)  /* R/W1C R 0x0000 0000 16/32 */
#define SH4A_PCIETLCTLR   (0x041048)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEDLSR   (0x04104C)  /* R/W1C R 0x4003 0000 16/32 */
#define SH4A_PCIEDLCTLR   (0x041050)  /* R R 0x0000 0000 16/32 */
#define SH4A_PCIEMACSR    (0x041054)  /* R/W1C R 0x0041 0000 16/32 */
#define SH4A_PCIEMACCTLR  (0x041058)  /* R/W R 0x0000 0000 16/32 */
#define   PCIEMACCTLR_SCR_DIS (1 << 27) /* scramble disable */
#define SH4A_PCIEPMSTR    (0x04105C)  /* R/W1C R 0x0000 0000 16/32 */
#define SH4A_PCIEPMCTLR   (0x041060)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIETLINTENR (0x041064)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEDLINTENR (0x041068)  /* R/W R 0x0000 0000 16/32 */
#define   PCIEDLINTENR_DLL_ACT_ENABLE (1 << 31) /* DL active irq */
#define SH4A_PCIEMACINTENR  (0x04106C)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIEPMINTENR (0x041070)  /* R/W R 0x0000 0000 16/32 */
#define SH4A_PCIETXDCTLR  (0x044000)  /* R/W - H'00000000_00000000 32/64 */
#define SH4A_PCIETXCTLR   (0x044020)  /* R/W - H'00000000_00000000 32/64 */
#define SH4A_PCIETXSR   (0x044028)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIETXVC0DCTLR (0x044100)  /* R/W - H'00000000_00000000 32/64 */
#define SH4A_PCIETXVC0SR  (0x044108)  /* R/W - H'00888000_00000000 32/64 */
#define SH4A_PCIEVC0PDTXR (0x044110)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0PHTXR (0x044118)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0NPDTXR  (0x044120)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0NPHTXR  (0x044128)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0CDTXR (0x044130)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0CHTXR (0x044138)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIETXVCXDCTLR (0x044200)  /* R/W - H'00000000_00000000 32/64 */
#define SH4A_PCIETXVCXSR  (0x044208)  /* R/W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXPDTXR (0x044210)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXPHTXR (0x044218)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXNPDTXR  (0x044220)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXNPHTXR  (0x044228)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXCDTXR (0x044230)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXCHTXR (0x044238)  /* W - H'00000000_00000000 32/64 */
#define SH4A_PCIERDCTLR   (0x046000)  /* RW - H'00000000_00000000 32/64 */
#define SH4A_PCIEERPCTLR  (0x046008)  /* RW - H'00000000_00000000 32/64 */
#define SH4A_PCIEERPHR    (0x046010)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEERPERR   (0x046018)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIERXVC0DCTLR (0x046100)  /* RW - H'00000000_00000000 32/64 */
#define SH4A_PCIERXVC0SR  (0x046108)  /* RW - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0PDRXR (0x046140)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0PHRXR (0x046148)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0PERR  (0x046150)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0NPDRXR  (0x046158)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0NPHRXR  (0x046160)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0NPERR (0x046168)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0CDRXR (0x046170)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0CHRXR (0x046178)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEVC0CERR  (0x046180)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIERXVCXDCTLR (0x046200)  /* RW - H'00000000_00000000 32/64 */
#define SH4A_PCIERXVCXSR  (0x046208)  /* RW - H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXPDRXR (0x046240)  /* R - H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXPHRXR (0x046248)  /* R H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXPERR  (0x046250)  /* R H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXNPDRXR  (0x046258)  /* R H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXNPHRXR  (0x046260)  /* R H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXNPERR (0x046268)  /* R H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXCDRXR (0x046270)  /* R H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXCHRXR (0x046278)  /* R H'00000000_00000000 32/64 */
#define SH4A_PCIEVCXCERR  (0x046280)  /* R H'00000000_00000000 32/64 */

/* SSI Register Definition for MSI WORK AROUND --hamada */
#define SH4A_PCI_SSI_BASE 0xFFE00000  /* spw config address */
#define SH4A_PCI_SSI_BASE_LEN 0x00100000  /* 1MB      */

#define SH4A_SSICR0   (0x000000)
#define SH4A_SSICR1   (0x010000)
#define SH4A_SSICR2   (0x020000)
#define SH4A_SSICR3   (0x030000)

#define PCI_REG(x)    ((x) + 0x40000)

static inline void
pci_write_reg (struct pci_channel * chan, unsigned long val, unsigned long reg)
{
  __raw_writel (val, chan->reg_base + reg);
}

static inline unsigned long
pci_read_reg (struct pci_channel * chan, unsigned long reg)
{
  return __raw_readl (chan->reg_base + reg);
}

#endif /* __PCI_SH7786_H */