/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : NasMmcSndMscc.c
  �� �� ��   : ����
  ��    ��   : L00171473
  ��������   : 2011��7��13��
  ����޸�   :
  ��������   : MMC����MSCC����Ϣ�Ĵ���
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2011��7��13��
    ��    ��   : L00171473
    �޸�����   : �����ļ�

******************************************************************************/

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/

#include "TafMmcInterface.h"
#include "MsccMmcInterface.h"
/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
/* ɾ��ExtAppMmcInterface.h*/
/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */
#include "NasMmSublayerDef.h"
#include "NasMmlCtx.h"
#include "NasMmcCtx.h"
#include "NasMmlLib.h"
#include "NasMmcSndMm.h"
#include "NasComm.h"
#include "NasMmcSndMscc.h"
#include "MnComm.h"
#include "NasMmcFsmMainTbl.h"
#include "NasMmcComFunc.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define    THIS_FILE_ID        PS_FILE_ID_NAS_MMC_SND_MSCC_C

/*****************************************************************************
  2 ȫ�ֱ�������
*****************************************************************************/

/*lint -save -e958 */

/*****************************************************************************
  3 ����ʵ��
*****************************************************************************/


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccUserSpecPlmnSearchCnf
 ��������  : ��MSCC�����û�ָ���ѵĽ��
 �������  : ucResult: ָ�������Ľ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��13��
   ��    ��   : L00171473
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccUserSpecPlmnSearchCnf(
    NAS_MSCC_PIF_USER_PLMN_SEARCH_RESULT_ENUM_UINT8         enResult
)
{
    MMC_MSCC_PLMN_SPECIAL_SEL_CNF_STRU *pstSpecPlmnSrchCnf = VOS_NULL_PTR;

    pstSpecPlmnSrchCnf = (MMC_MSCC_PLMN_SPECIAL_SEL_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                             sizeof(MMC_MSCC_PLMN_SPECIAL_SEL_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstSpecPlmnSrchCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccUserSpecPlmnSearchCnf():ERROR:Memory Alloc Error for pstSpecPlmnSrchCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstSpecPlmnSrchCnf)+VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_PLMN_SPECIAL_SEL_CNF_STRU)- VOS_MSG_HEAD_LENGTH);
    pstSpecPlmnSrchCnf->enResult                    = enResult;

    /* �����Ϣͷ */
    pstSpecPlmnSrchCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_PLMN_SPECIAL_SEL_CNF;
    pstSpecPlmnSrchCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstSpecPlmnSrchCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstSpecPlmnSrchCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstSpecPlmnSrchCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstSpecPlmnSrchCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_PLMN_SPECIAL_SEL_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstSpecPlmnSrchCnf);

    return;
}

#if (FEATURE_ON == FEATURE_CSG)
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccUserCsgListAbortCnf
 ��������  : ��MSCC�����û�CSG list����ֹ�Ľ��
 �������  : pstCsgListAbortCnf - ��Ϣ����
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��9��10��
   ��    ��   : z00161729
   �޸�����   : ֧��LTE CSG��������

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccUserCsgListAbortCnf(
    MMC_MSCC_CSG_LIST_ABORT_CNF_STRU   *pstCsgListAbortCnf
)
{
    MMC_MSCC_CSG_LIST_ABORT_CNF_STRU   *pstMsg = VOS_NULL_PTR;

    pstMsg = (MMC_MSCC_CSG_LIST_ABORT_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                              sizeof(MMC_MSCC_CSG_LIST_ABORT_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstMsg )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccUserCsgListAbortCnf():ERROR:Memory Alloc Error for pstPlmnListAbortCnf ");
        return;
    }

    /* �����Ϣͷ */
    PS_MEM_SET(((VOS_UINT8*)pstMsg) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_CSG_LIST_ABORT_CNF_STRU) - VOS_MSG_HEAD_LENGTH);
    pstMsg->MsgHeader.ulMsgName         = ID_MMC_MSCC_CSG_LIST_ABORT_CNF;
    pstMsg->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMsg->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstMsg->MsgHeader.ulLength          = sizeof(MMC_MSCC_CSG_LIST_ABORT_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    /* ������������ϢΪ��ָ�����ʾ�б�Ϊ�� */
    if ( VOS_NULL_PTR == pstCsgListAbortCnf)
    {
        pstMsg->stCsgIdInfo.ulPlmnWithCsgIdNum = 0;

        PS_SEND_MSG(WUEPS_PID_MMC, pstMsg);

        return;
    }

    PS_MEM_CPY(&pstMsg->stCsgIdInfo, &pstCsgListAbortCnf->stCsgIdInfo, sizeof(pstMsg->stCsgIdInfo));

    PS_SEND_MSG(WUEPS_PID_MMC, pstMsg);
    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccUserCsgListSearchCnf
 ��������  : ��MSCC�����û�CSG list�ѵĽ��
 �������  : pstCsgListSearchCnf - ��Ϣ����
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��9��10��
   ��    ��   : z00161729
   �޸�����   : ֧��LTE CSG��������

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccUserCsgListSearchCnf(
    MMC_MSCC_CSG_LIST_SEARCH_CNF_STRU  *pstCsgListSearchCnf
)
{
    MMC_MSCC_CSG_LIST_SEARCH_CNF_STRU   *pstMsg = VOS_NULL_PTR;

    pstMsg = (MMC_MSCC_CSG_LIST_SEARCH_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_CSG_LIST_SEARCH_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstMsg )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccUserCsgListSearchCnf():ERROR:Memory Alloc Error ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstMsg) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_CSG_LIST_SEARCH_CNF_STRU) - VOS_MSG_HEAD_LENGTH);


    /* �����Ϣͷ */
    pstMsg->MsgHeader.ulMsgName         = ID_MMC_MSCC_CSG_LIST_SEARCH_CNF;
    pstMsg->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMsg->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstMsg->MsgHeader.ulLength          = sizeof(MMC_MSCC_CSG_LIST_SEARCH_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    /* ������������ϢΪ��ָ�����ʾ�б�Ϊ�� */
    if ( VOS_NULL_PTR == pstCsgListSearchCnf)
    {
        pstMsg->stCsgIdInfo.ulPlmnWithCsgIdNum = 0;
        PS_SEND_MSG(WUEPS_PID_MMC, pstMsg);

        return;
    }

    PS_MEM_CPY(&pstMsg->stCsgIdInfo, &pstCsgListSearchCnf->stCsgIdInfo, sizeof(pstMsg->stCsgIdInfo));

    PS_SEND_MSG(WUEPS_PID_MMC, pstMsg);
    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccCsgListSearchRej
 ��������  : ��MSCC�����û�CSG list��rej
 �������  : ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��9��10��
   ��    ��   : z00161729
   �޸�����   : ֧��LTE CSG��������

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccCsgListSearchRej(VOS_VOID)
{
    MMC_MSCC_CSG_LIST_REJ_STRU         *pstCsgListRej = VOS_NULL_PTR;

    pstCsgListRej = (MMC_MSCC_CSG_LIST_REJ_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_CSG_LIST_REJ_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstCsgListRej )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccCsgListSearchRej():ERROR:Memory Alloc Error ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstCsgListRej) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_CSG_LIST_REJ_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstCsgListRej->MsgHeader.ulMsgName         = ID_MMC_MSCC_CSG_LIST_REJ;
    pstCsgListRej->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstCsgListRej->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstCsgListRej->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstCsgListRej->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstCsgListRej->MsgHeader.ulLength          = sizeof(MMC_MSCC_CSG_LIST_REJ_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstCsgListRej);
    return;
}

#endif

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccPlmnReselCnf
 ��������  : ��MSCC����at+cops=0�Ľ��
 �������  : ucResult: ָ�������Ľ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��13��
   ��    ��   : L00171473
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccPlmnReselCnf(
    NAS_MSCC_PIF_USER_PLMN_SEARCH_RESULT_ENUM_UINT8         enPlmnReselRslt
)
{
    MMC_MSCC_PLMN_RESEL_CNF_STRU       *pstReselPlmnSrchCnf = VOS_NULL_PTR;

    pstReselPlmnSrchCnf = (MMC_MSCC_PLMN_RESEL_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                              sizeof(MMC_MSCC_PLMN_RESEL_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstReselPlmnSrchCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccPlmnReselCnf():ERROR:Memory Alloc Error for pstReselPlmnSrchCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstReselPlmnSrchCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_PLMN_RESEL_CNF_STRU) - VOS_MSG_HEAD_LENGTH);
    pstReselPlmnSrchCnf->enResult                    = enPlmnReselRslt;

    pstReselPlmnSrchCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_PLMN_RESEL_CNF;
    pstReselPlmnSrchCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstReselPlmnSrchCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstReselPlmnSrchCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstReselPlmnSrchCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstReselPlmnSrchCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_PLMN_RESEL_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstReselPlmnSrchCnf);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccPlmnSelectStartInd
 ��������  : ��MSCC�ϱ�������ʼ�ı�ʾ
 �������  : enFlag
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2013��10��09��
   ��    ��   : l00208543
   �޸�����   : DTS2013100904573 �����ɺ���

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccPlmnSelectStartInd(VOS_VOID)
{
    MMC_MSCC_PLMN_SELECTION_START_IND_STRU  *pstPlmnSeleStartInd = VOS_NULL_PTR;

    pstPlmnSeleStartInd = (MMC_MSCC_PLMN_SELECTION_START_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                           sizeof(MMC_MSCC_PLMN_SELECTION_START_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstPlmnSeleStartInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccPlmnSelectStartInd():ERROR:Memory Alloc Error for pstPlmnSelRlstInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstPlmnSeleStartInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_PLMN_SELECTION_START_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    pstPlmnSeleStartInd->enPlmnSeleStartFlag         = NAS_MSCC_PIF_PLMN_SELECTION_START;

    /* �����Ϣͷ */
    pstPlmnSeleStartInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_PLMN_SELE_START_IND;
    pstPlmnSeleStartInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPlmnSeleStartInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPlmnSeleStartInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPlmnSeleStartInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPlmnSeleStartInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_PLMN_SELECTION_START_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstPlmnSeleStartInd);
    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccPlmnSelectionRsltInd
 ��������  : ��MSCC�ϱ���ǰ���������
 �������  : enResult: �������
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��22��
   ��    ��   : L00171473
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
 3.��    ��   : 2015��4��17��
   ��    ��   : w00176964
   �޸�����   : CDMA 1X Iteration 10 Modified:add lte coverage flg and notify mscc
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccPlmnSelectionRsltInd(
    NAS_MSCC_PIF_PLMN_SELECTION_RESULT_ENUM_UINT32          enResult,
    VOS_UINT8                                               ucLteCoverFlg
)
{
    NAS_MSCC_PIF_PLMN_SELECTION_RLST_IND_STRU                   *pstPlmnSelRlstInd = VOS_NULL_PTR;

    pstPlmnSelRlstInd = (NAS_MSCC_PIF_PLMN_SELECTION_RLST_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(NAS_MSCC_PIF_PLMN_SELECTION_RLST_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstPlmnSelRlstInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccPlmnSelectionRsltInd():ERROR:Memory Alloc Error for pstPlmnSelRlstInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstPlmnSelRlstInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(NAS_MSCC_PIF_PLMN_SELECTION_RLST_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    pstPlmnSelRlstInd->enResult                    = enResult;

    /* �����Ϣͷ */
    pstPlmnSelRlstInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_PLMN_SELECTION_RLST_IND;
    pstPlmnSelRlstInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPlmnSelRlstInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPlmnSelRlstInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPlmnSelRlstInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPlmnSelRlstInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_PLMN_SELECTION_RLST_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstPlmnSelRlstInd->ucLteCoverageFlg = ucLteCoverFlg;

    PS_SEND_MSG(WUEPS_PID_MMC, pstPlmnSelRlstInd);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccDetachInd
 ��������  : ��MSCC����TAFMMC_DETACH_IND��Ϣ
 �������  : VOS_UINT32                          ulCnDomainId
             VOS_UINT32                          ulDetachType
             VOS_UINT32                          ulCause
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��11��
   ��    ��   : lijun 00171473
   �޸�����   : �޸ĺ�����������ʵ�� for V7R1 phase II
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccDetachInd(
    VOS_UINT32                          ulCnDomainId,
    VOS_UINT32                          ulDetachType,
    VOS_UINT32                          ulCause
)
{
    MMC_MSCC_DETACH_IND_STRU            *pstDetachInd   = VOS_NULL_PTR;
    NAS_MMC_SERVICE_INFO_CTX_STRU      *pstServiceInfo = VOS_NULL_PTR;

    pstDetachInd = (MMC_MSCC_DETACH_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_DETACH_IND_STRU)- VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstDetachInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccDetachInd():ERROR:Memory Alloc Error for pstDetachInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstDetachInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_DETACH_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��ȡ����״̬ */
    pstServiceInfo = NAS_MMC_GetServiceInfo();

    pstDetachInd->enCnDomainId                = ulCnDomainId;
    if (NAS_MSCC_PIF_SRVDOMAIN_CS == ulCnDomainId)
    {
        /* CS����Ϣ��Ч, ��д"CS����״̬" */
        pstDetachInd->enServiceStatus = pstServiceInfo->enCsCurrService;
    }
    else if (NAS_MSCC_PIF_SRVDOMAIN_PS == ulCnDomainId)
    {
        /* PS����Ϣ��Ч, ��д"PS����״̬" */
        pstDetachInd->enServiceStatus = pstServiceInfo->enPsCurrService;
    }
    else
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccDetachInd():ERROR: ulCnDomainId Error ");

        /* �ͷ��ڴ� */
        PS_MEM_FREE(WUEPS_PID_MMC, pstDetachInd);

        return;
    }

    /* �����Ϣͷ */
    pstDetachInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_DETACH_IND;
    pstDetachInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstDetachInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstDetachInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstDetachInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstDetachInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_DETACH_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstDetachInd->ulDetachCause               = ulCause;
    pstDetachInd->enNetworkDetachType         = (VOS_UINT8)ulDetachType;

    pstDetachInd->ucOriginalDetachCause       = NAS_MML_GetOriginalRejectCause(pstDetachInd->ulDetachCause);

    PS_SEND_MSG(WUEPS_PID_MMC, pstDetachInd);

    return;
}



/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccAttachCnf
 ��������  : ����ԭ��D_MMC_ATTACH_CNF�Ĺ�������
 �������  : VOS_UINT32  ulCnDomainId
             VOS_UINT32  ulServiceStatus
             VOS_UINT32  ulOpid
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��7��14��
    ��    ��   : ��ë/00166186
    �޸�����   : �����ɺ���
  2.��    ��   : 2012��4��27��
    ��    ��   : l00130025
    �޸�����   : DTS2012032303156:MMC�ķ���״̬���ϱ��ķ���״̬��Ҫת��
  3.��    ��   : 2013��3��30��
    ��    ��   : l00167671
    �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccAttachCnf(
     VOS_UINT32                                             ulCnDomainId,
     NAS_MM_COM_SERVICE_STATUS_ENUM_UINT8                   enMsccServiceStatus,
     VOS_UINT32                                             ulOpid
)
{
    MMC_MSCC_ATTACH_CNF_STRU           *pstAttachCnf = VOS_NULL_PTR;

    pstAttachCnf = (MMC_MSCC_ATTACH_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_ATTACH_CNF_STRU)- VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstAttachCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccAttachCnf():ERROR:Memory Alloc Error for pstAttachCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstAttachCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_ATTACH_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstAttachCnf->enServiceStatus             = enMsccServiceStatus;
    pstAttachCnf->enCnDomainId                = ulCnDomainId;
    pstAttachCnf->ulOpID                      = NAS_MMC_GetAttachReqOpId();

    /* �����Ϣͷ */
    pstAttachCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_ATTACH_CNF;
    pstAttachCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstAttachCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstAttachCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstAttachCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstAttachCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_ATTACH_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstAttachCnf);
    return;
}
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccDetachCnf
 ��������  : ����ԭ��D_MMC_DETACH_CNF�Ĺ�������
 �������  : VOS_UINT32  ulCnDomainId
             VOS_UINT32  ulServiceStatus
             VOS_UINT32  ulOpid
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��7��14��
    ��    ��   : ��ë/00166186
    �޸�����   : �����ɺ���
  2.��    ��   : 2012��4��27��
    ��    ��   : l00130025
    �޸�����   : DTS2012032303156:MMC�ķ���״̬���ϱ��ķ���״̬��Ҫת��
  3.��    ��   : 2013��3��30��
    ��    ��   : l00167671
    �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccDetachCnf(
    VOS_UINT32                                              ulCnDomainId,
    NAS_MM_COM_SERVICE_STATUS_ENUM_UINT8                    enMsccServiceStatus,
    VOS_UINT32                                              ulOpid,
    NAS_MSCC_PIF_OPER_RESULT_ENUM_UINT32                    enOperRslt
)
{
    MMC_MSCC_DETACH_CNF_STRU            *pstDetachCnf = VOS_NULL_PTR;

    pstDetachCnf = (MMC_MSCC_DETACH_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_DETACH_CNF_STRU)- VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstDetachCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccDetachCnf():ERROR:Memory Alloc Error for pstDetachCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstDetachCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_DETACH_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstDetachCnf->enServiceStatus             = enMsccServiceStatus;
    pstDetachCnf->enCnDomainId                = ulCnDomainId;
    pstDetachCnf->enOperRslt                  = enOperRslt;

    pstDetachCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_DETACH_CNF;
    pstDetachCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstDetachCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstDetachCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstDetachCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstDetachCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_DETACH_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstDetachCnf);

    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccServiceStatusInd
 ��������  : ��MSCC���ͷ���״ָ̬ʾ
 �������  : ulCnDomainId    - ������
             ulServiceStatus - ����״̬
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��19��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
 3.��    ��   : 2013��11��20��
   ��    ��   : w00176964
   �޸�����   : Volte PhaseII��Ŀ�޸�:����CSPS��SIM��״̬
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccServiceStatusInd(
    VOS_UINT32                          ulCnDomainId,
    VOS_UINT32                          ulServiceStatus
)
{
    /* ��MMC_MSCC_SERVICE_STATUS_IND_STRU��Ϣ�����װ */
    MMC_MSCC_SERVICE_STATUS_IND_STRU   *pstServiceStatusInd = VOS_NULL_PTR;

    pstServiceStatusInd = (MMC_MSCC_SERVICE_STATUS_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                              sizeof(MMC_MSCC_SERVICE_STATUS_IND_STRU)- VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstServiceStatusInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccServiceStatusInd():ERROR:Memory Alloc Error for pstServiceStatusInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstServiceStatusInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_SERVICE_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* Modified by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-11-22, begin */
    pstServiceStatusInd->bitOpSrvSta                 = VOS_TRUE;
    pstServiceStatusInd->bitOpRegSta                 = VOS_FALSE;
    pstServiceStatusInd->enServiceStatus             = ulServiceStatus;
    pstServiceStatusInd->enCnDomainId                = ulCnDomainId;
    pstServiceStatusInd->ucSimCsRegStatus            = NAS_MML_GetSimCsRegStatus();
    pstServiceStatusInd->ucSimPsRegStatus            = NAS_MML_GetSimPsRegStatus();
    /* Modified by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-11-22, end */

    /* �����Ϣͷ */
    pstServiceStatusInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_SERVICE_STATUS_IND;
    pstServiceStatusInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstServiceStatusInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstServiceStatusInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstServiceStatusInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstServiceStatusInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_SERVICE_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstServiceStatusInd);
    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccRegStatusInd
 ��������  : ��MSCC����ע��״ָ̬ʾ
 �������  : ulCnDomainId - ������
             enRegStatus  - ע��״̬
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2013��4��7��
   ��    ��   : z00161729
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccRegStatusInd(
    VOS_UINT32                          ulCnDomainId,
    NAS_MSCC_PIF_REG_STATE_ENUM_UINT8   enRegStatus
)
{
    /* ��MMC_MSCC_SERVICE_STATUS_IND_STRU��Ϣ�����װ */
    MMC_MSCC_SERVICE_STATUS_IND_STRU    *pstServiceStatusInd = VOS_NULL_PTR;

    pstServiceStatusInd = (MMC_MSCC_SERVICE_STATUS_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                    sizeof(MMC_MSCC_SERVICE_STATUS_IND_STRU)- VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstServiceStatusInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccServiceStatusInd():ERROR:Memory Alloc Error for pstServiceStatusInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstServiceStatusInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_SERVICE_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* Modified by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-11-22, begin */
    pstServiceStatusInd->bitOpSrvSta                 = VOS_FALSE;
    pstServiceStatusInd->bitOpRegSta                 = VOS_TRUE;
    pstServiceStatusInd->enRegState                  = enRegStatus;
    pstServiceStatusInd->enCnDomainId                = ulCnDomainId;
    pstServiceStatusInd->ucSimCsRegStatus            = NAS_MML_GetSimCsRegStatus();
    pstServiceStatusInd->ucSimPsRegStatus            = NAS_MML_GetSimPsRegStatus();
    /* Modified by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-11-22, end */

    if (NAS_MSCC_PIF_SRVDOMAIN_CS == ulCnDomainId)
    {
        pstServiceStatusInd->ulOosCause              = NAS_MML_GetErrLogCsOosCause();
    }
    else
    {
        pstServiceStatusInd->ulOosCause              = NAS_MML_GetErrLogPsOosCause();
    }

    /* �����Ϣͷ */
    pstServiceStatusInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_SERVICE_STATUS_IND;
    pstServiceStatusInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstServiceStatusInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstServiceStatusInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstServiceStatusInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstServiceStatusInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_SERVICE_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstServiceStatusInd);
    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccCoverageLost
 ��������  : ��MSCC���Ͷ���ָʾ
 �������  : ucType - �����������ǽ�����������
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��7��20��
    ��    ��   : l00130025
    �޸�����   : �����ɺ���
  2.��    ��   : 2012��4��27��
    ��    ��   : l00130025
    �޸�����   : DTS2012032303156:MMC�ķ���״̬���ϱ��ķ���״̬��Ҫת��
  3.��    ��   : 2013��3��30��
    ��    ��   : l00167671
    �޸�����   : �����ϱ�AT�������������C��
  4.��    ��   : 2015��10��28��
    ��    ��   : s00217060
    �޸�����   : ROAM_PLMN_SELECTION_OPTIMIZE_3.0�޸�
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccCoverageInd(
    VOS_UINT8                           ucType
)
{
    MMC_MSCC_COVERAGE_AREA_IND_STRU    *pstCoverageInd   = VOS_NULL_PTR;
    NAS_MML_PLMN_ID_STRU               *pstCurrPlmn      = VOS_NULL_PTR;
    VOS_UINT32                          ulDeepTimerLen;

    pstCoverageInd = (MMC_MSCC_COVERAGE_AREA_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_COVERAGE_AREA_IND_STRU)- VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstCoverageInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccCoverageInd():ERROR:Memory Alloc Error for pstCoverageInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstCoverageInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_COVERAGE_AREA_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if ( NAS_MSCC_PIF_COVERAGE_AREA_CHANGE_MODE_LOST == ucType)
    {
        pstCoverageInd->enCoverageChgMode  = NAS_MSCC_PIF_COVERAGE_AREA_CHANGE_MODE_LOST;
    }
    else
    {
        pstCoverageInd->enCoverageChgMode  = NAS_MSCC_PIF_COVERAGE_AREA_CHANGE_MODE_ENTER;

    }

    pstCoverageInd->enCsSvcSta             = NAS_MMC_GetServiceStatusForMscc(NAS_MSCC_PIF_SRVDOMAIN_CS);
    pstCoverageInd->enPsSvcSta             = NAS_MMC_GetServiceStatusForMscc(NAS_MSCC_PIF_SRVDOMAIN_PS);

    /* ���ڻ�ȡ��ǰפ�������PLMN */
    pstCurrPlmn = NAS_MML_GetCurrCampPlmnId();

    pstCoverageInd->stPlmnId.ulMcc           = pstCurrPlmn->ulMcc;
    pstCoverageInd->stPlmnId.ulMnc           = pstCurrPlmn->ulMnc;

    /* ���ڻ�ȡavailable timer��ʱ����˯��ʱ�� */
    ulDeepTimerLen = (NAS_MMC_GetPhaseTwoPeriodicSleepTimerLen()) * NAS_MML_ONE_THOUSAND_MILLISECOND;
    if ( NAS_MMC_GetNextAvailableTimerValue() < ulDeepTimerLen)
    {
        pstCoverageInd->ulTimMaxFlg        = VOS_FALSE;
    }
    else
    {
        pstCoverageInd->ulTimMaxFlg        = VOS_TRUE;
    }

    /* �����Ϣͷ */
    pstCoverageInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_COVERAGE_AREA_IND;
    pstCoverageInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstCoverageInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstCoverageInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstCoverageInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstCoverageInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_COVERAGE_AREA_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstCoverageInd);

    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccMmInfo
 ��������  : �ϱ������·���MM INFO��Ϣ�а����������Ϣ
 �������  : NAS_MM_INFO_IND_STRU *pstMmInfo - MM INFO�ṹ��ָ��
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��25��
   ��    ��   : o00132663
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccMmInfo(
    NAS_MM_INFO_IND_STRU               *pstMmInfo
)
{
    MMC_MSCC_MM_INFO_IND_STRU           *pstMmInfoInd       = VOS_NULL_PTR;
    NAS_MML_OPERATOR_NAME_INFO_STRU    *pstNasOperatorName = VOS_NULL_PTR;

    pstMmInfoInd = (MMC_MSCC_MM_INFO_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_MM_INFO_IND_STRU)- VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstMmInfoInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccMmInfo():ERROR:Memory Alloc Error for pstMmInfoInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstMmInfoInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_MM_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��MMC_MSCC_MM_INFO_IND_STRU��Ϣ��װ���� */
    pstMmInfoInd->ucIeFlg        = pstMmInfo->ucIeFlg;
    pstMmInfoInd->ucDST          = pstMmInfo->ucDST;
    pstMmInfoInd->cLocalTimeZone = pstMmInfo->cLocalTimeZone;
    PS_MEM_CPY(pstMmInfoInd->aucLSAID, pstMmInfo->ucLSAID, sizeof(pstMmInfoInd->aucLSAID));
    pstMmInfoInd->stUniversalTimeandLocalTimeZone = pstMmInfo->stUniversalTimeandLocalTimeZone;
    pstNasOperatorName           = NAS_MML_GetOperatorNameInfo();
    pstMmInfoInd->stName         = *pstNasOperatorName;

    /* �����Ϣͷ */
    pstMmInfoInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_MM_INFO_IND;
    pstMmInfoInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMmInfoInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMmInfoInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMmInfoInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstMmInfoInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_MM_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstMmInfoInd);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccDataTranAttri
 ��������  : �ϱ���ǰPDP�������
 �������  : ucDataTranAttri:PDP�����־
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��20��
   ��    ��   : zhoujun \40661
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccDataTranAttri(
    NAS_MSCC_PIF_DATATRAN_ATTRI_ENUM_UINT8                  ucDataTranAttri
)
{
    MMC_MSCC_DATATRAN_ATTRI_IND_STRU    *pstDataTransAttriInd = VOS_NULL_PTR;

    pstDataTransAttriInd = (MMC_MSCC_DATATRAN_ATTRI_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                               sizeof(MMC_MSCC_DATATRAN_ATTRI_IND_STRU)- VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstDataTransAttriInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccDataTranAttri():ERROR:Memory Alloc Error for pstDataTransAttriInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstDataTransAttriInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_DATATRAN_ATTRI_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    pstDataTransAttriInd->enDataTranAttri             = ucDataTranAttri;

    /* �����Ϣͷ */
    pstDataTransAttriInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_DATATRAN_ATTRI_IND;
    pstDataTransAttriInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstDataTransAttriInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstDataTransAttriInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstDataTransAttriInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstDataTransAttriInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_DATATRAN_ATTRI_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstDataTransAttriInd);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccSysInfo
 ��������  : ����MSCCϵͳ��Ϣ
 �������  : ulMsgType:��Ϣ����
             MmRegState:MM���ע��״̬
             GmmRegState:GMM���ע��״̬
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��20��
   ��    ��   : zhoujun \40661
   �޸�����   : �����ɺ���
 2.��    ��   : 2011��11��30��
   ��    ��   : H00202780
   �޸����� :���Ӷ�LMM�ϱ��ķ���״̬����ע��״̬�ϱ���MMA
 3.��    ��   : 2012��4��27��
   ��    ��   : l00130025
   �޸�����   : DTS2012032303156:MMC�ķ���״̬���ϱ��ķ���״̬��Ҫת��
 4.��    ��   : 2012��06��13��
   ��    ��   : s46746
   �޸�����   : For CS/PS mode 1���޸�LTEϵͳ��ģʽ
 5.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
 6.��    ��   : 2013��11��22��
   ��    ��   : z00161729
   �޸�����   : SVLTE�Ż�G-TL ps�л������޸�
 7.��    ��   : 2013��10��16��
   ��    ��   : w00176964
   �޸�����   : VoLTE_PhaseII ��Ŀ:����������Ϣ����
 8.��    ��   : 2014��01��17��
   ��    ��   : l00198894
   �޸�����   : V9R1C53 C+L ������ѡ��Ŀ
 9.��    ��   : 2014��2��14��
   ��    ��   : z00161729
   �޸�����   : DTS2014021000537:sim��anycellפ��l��С��mmc�յ�ϵͳ��Ϣת��mmaʱӦ�ý���ֹ�����ʶ��ΪTRUE��
                ���ϱ�pstransfer:1,������psǨ�Ƶ�modem0��l��ע�ᣬƹ��psǨ��
 10.��    ��   : 2014��2��20��
    ��    ��   : z00161729
    �޸�����   : DTS2014022100125:����פ��g�����磬��˫����tl����������פ��g�����磬
               available��ʱ��list�������������б���last rplmn rat������ǰ�浼��g
               ���ڵ�һ���޷���l��tds������
 11.��    ��   : 2014��2��14��
   ��    ��   : s00246516
   �޸�����   : L-C��������Ŀ:���ӻ�ȡ��ע������Ĵ���
 12.��    ��   : 2014��8��14��
    ��    ��   : s00217060
    �޸�����   : DTS2014080700822:LTEפ����С����FDD����TDD�ϱ���MMA
 13.��    ��   : 2015��4��2��
   ��    ��   : b00269685
   �޸�����   : ����EPLMN����home������ʾΪ������
 14.��    ��   : 2015��8��13��
    ��    ��   : l00289540
    �޸�����   : User_Exp_Improve�޸�
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccSysInfo( VOS_VOID )
{
    MMC_MSCC_SYS_INFO_IND_STRU          *pstSysInfoInd       = VOS_NULL_PTR;
    NAS_MML_CAMP_PLMN_INFO_STRU        *pstCampPlmnInfo     = VOS_NULL_PTR;
    VOS_UINT32                          i;
    VOS_UINT32                          ulIsHplmnInEplmnList;

    VOS_UINT32                          ulIsCurrCampPlmnInEplmnList;

    VOS_UINT32                          ulForbiddenFlg;

#if (FEATURE_ON == FEATURE_LTE)
    MMC_LMM_PLMN_ID_STRU                stLmmPlmnId;
#endif

    ulForbiddenFlg            = VOS_FALSE;
    ulIsHplmnInEplmnList      = NAS_MML_IsHplmnInEplmnList();

    ulIsCurrCampPlmnInEplmnList = NAS_MML_IsCurrCampPlmnInEplmnList();

    pstSysInfoInd = (MMC_MSCC_SYS_INFO_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_SYS_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstSysInfoInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccSysInfo():ERROR:Memory Alloc Error for pstSysInfoInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstSysInfoInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_SYS_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ���MMC_MSCC_SYS_INFO_IND_STRU��Ϣ*/
    pstCampPlmnInfo                             = NAS_MML_GetCurrCampPlmnInfo();

    pstSysInfoInd->stCellId.ucCellNum                  = pstCampPlmnInfo->stCampCellInfo.ucCellNum;
    for ( i = 0; i < pstCampPlmnInfo->stCampCellInfo.ucCellNum ; i++ )
    {
        pstSysInfoInd->stCellId.aulCellId[i] = pstCampPlmnInfo->stCampCellInfo.astCellInfo[i].ulCellId;
    }

    pstSysInfoInd->ucRac            = pstCampPlmnInfo->ucRac;
    pstSysInfoInd->usLac            = (pstCampPlmnInfo->stLai.aucLac[0] << 8) | (pstCampPlmnInfo->stLai.aucLac[1]);
    pstSysInfoInd->stPlmnId.ulMcc   = pstCampPlmnInfo->stLai.stPlmnId.ulMcc;
    pstSysInfoInd->stPlmnId.ulMnc   = pstCampPlmnInfo->stLai.stPlmnId.ulMnc;
    pstSysInfoInd->enCurNetWork     = NAS_MML_GetCurrNetRatType();
    pstSysInfoInd->ucSysSubMode     = NAS_MMC_CovertMmlSysSubModeToMsccSysSubMode(pstCampPlmnInfo->enSysSubMode);

    pstSysInfoInd->ucCsAttachAllowFlag = NAS_MML_GetCsAttachAllowFlg();
    pstSysInfoInd->ucPsAttachAllowFlag = NAS_MML_GetPsAttachAllowFlg();

    /* Added by s00246516 for L-C��������Ŀ, 2014-02-14, Begin */
    pstSysInfoInd->ulArfcn          = NAS_MML_GetCurrCampArfcn();
    pstSysInfoInd->enPrioClass      = NAS_MMC_GetPlmnPrioClass(&(pstCampPlmnInfo->stLai.stPlmnId));
    /* Added by s00246516 for L-C��������Ŀ, 2014-02-14, End */

    ulForbiddenFlg = NAS_MMC_GetCurrentLaiForbbidenType();

#if (FEATURE_ON == FEATURE_LTE)
    if (NAS_MML_NET_RAT_TYPE_LTE == NAS_MML_GetCurrNetRatType())
    {
        /* ��PLMN ID����ת�� */
        NAS_MML_ConvertNasPlmnToLMMFormat(&stLmmPlmnId, &pstCampPlmnInfo->stLai.stPlmnId);

        /* ��ֹ�������access bar����Ϊ��forbidden plmn */
        if (MMC_LMM_PLMN_ALLOW_REG != Nas_PlmnIdIsForbid(&stLmmPlmnId))
        {
            ulForbiddenFlg = VOS_TRUE;
        }


        pstSysInfoInd->enLmmAccessType  = pstCampPlmnInfo->enLmmAccessType;
    }
    else
#endif
    {
        if (VOS_TRUE == NAS_MML_GetPsRestrictRegisterFlg())
        {
            ulForbiddenFlg = MMCMM_FORBIDDEN_PLMN;
        }

        pstSysInfoInd->enLmmAccessType  = NAS_MML_LMM_ACCESS_TYPE_BUTT;
    }

    pstSysInfoInd->ucIsFobbiddenPlmnFlag = (VOS_UINT8)ulForbiddenFlg;

    /* Modified by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-16, begin */
    pstSysInfoInd->ucRoamFlag       = VOS_FALSE;

    pstSysInfoInd->ucPsSupportFlg   = NAS_MML_GetPsSupportFLg();

    /* ��Hplmn��CSע�ᱻ�ܺ󣬷�E5ʱ�����ڷ���ע�� ,E5ʱ��HplmnRejlist����¼ֵ */
    if (VOS_TRUE == NAS_MML_ComparePlmnIdWithHplmn(NAS_MML_GetCurrCampPlmnId()))
    {
        if (VOS_FALSE == NAS_MMC_GetHPlmnSpecDomainAccessCapa(NAS_MMC_REG_DOMAIN_PS))
        {
            if (MMCMM_NO_FORBIDDEN == ulForbiddenFlg)
            {
                pstSysInfoInd->ucIsFobbiddenPlmnFlag = MMCMM_FORBIDDEN_PLMN;
            }

            if ( VOS_TRUE == NAS_MML_GetHplmnRegisterCtrlFlg())
            {
                pstSysInfoInd->ucIsFobbiddenPlmnFlag  &= (~MMCMM_FORBIDDEN_PLMN);
            }
        }
    }
    else
    {

        /* ��ǰפ������϶�����HOME PLMN��,Ĭ������ */
        pstSysInfoInd->ucRoamFlag   = VOS_TRUE;

        /* ���NV������EPLMN������HPLMN����Ҫ��������Ϊ����ʾ���� */
        if ((VOS_TRUE == NAS_MML_GetHplmnInEplmnDisplayHomeFlg())
         && (VOS_TRUE == ulIsHplmnInEplmnList)
         && (VOS_TRUE == ulIsCurrCampPlmnInEplmnList))
        {
            pstSysInfoInd->ucRoamFlag   = VOS_FALSE;
        }
    }
    /* Modified by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-16, end */

    /* �����Ϣͷ */
    pstSysInfoInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_SYS_INFO_IND;
    pstSysInfoInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstSysInfoInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstSysInfoInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstSysInfoInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstSysInfoInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_SYS_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstSysInfoInd);
    return;
}


/* Modified by w00176964 for VoLTE_PhaseIII ��Ŀ, 2013-12-13, begin */
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccRegResultInd
 ��������  : ����MSCCָ���������ע������Ϣ
 �������  : enSrvDomain-----��ǰע��ķ�����
             ucResult   -----��ǰע����
             enRejCause -----��ǰע��ʧ�ܵ�ԭ��ֵ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2013��8��15��
   ��    ��   : l00208543
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��12��13��
   ��    ��   : W00176964
   �޸�����   : Volte PhaseIII��Ŀ�޸�:�޸���Ϣ����Ϣ�ṹ����
 3.��    ��   : 2014��4��3��
   ��    ��   : z00161729
   �޸�����   : DTS2014040300125:service ���ܺ�����detach ind������Ҫ�ϱ�^rejinfo

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccRegResultInd(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32            enSrvDomain,
    VOS_UINT8                           ucResult,
    NAS_MML_REG_FAIL_CAUSE_ENUM_UINT16  enRejCause
)
{
    MMC_MSCC_REG_RESULT_IND_STRU        *pstRegResultInd       = VOS_NULL_PTR;

    pstRegResultInd = (MMC_MSCC_REG_RESULT_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_REG_RESULT_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstRegResultInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccRegResultInd():ERROR:Memory Alloc Error for pstRejInfoInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstRegResultInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_REG_RESULT_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣ*/
    pstRegResultInd->enCnDomainId   = enSrvDomain;
    pstRegResultInd->ucRegRslt      = ucResult;

    if (VOS_FALSE == ucResult)
    {
        pstRegResultInd->enRejCause     = enRejCause;
        pstRegResultInd->ucOriginalRejCause = NAS_MML_GetOriginalRejectCause(pstRegResultInd->enRejCause);
        /* ֻ�ϱ�С�ڵ���256���ߵ���258��301��302��303�ľܾ�ԭ��ֵ�������ڲ���չ�ľܾ�ԭ��ֵ�������ϱ� */
        if ((pstRegResultInd->enRejCause <= NAS_MML_REG_FAIL_CAUSE_AUTH_REJ)
         || (NAS_MML_REG_FAIL_CAUSE_COMB_REG_CS_FAIL_OTHER_CAUSE == pstRegResultInd->enRejCause)
         || (NAS_MML_REG_FAIL_CAUSE_TIMER_TIMEOUT == pstRegResultInd->enRejCause)
         || (NAS_MML_REG_FAIL_CAUSE_RR_CONN_EST_FAIL == pstRegResultInd->enRejCause)
         || (NAS_MML_REG_FAIL_CAUSE_RR_CONN_FAIL == pstRegResultInd->enRejCause))
        {
            pstRegResultInd->ucReportCauseCtrl = VOS_TRUE;
        }
    }

    /* �����Ϣͷ */
    pstRegResultInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_REG_RESULT_IND;
    pstRegResultInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstRegResultInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstRegResultInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstRegResultInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstRegResultInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_REG_RESULT_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstRegResultInd);

    return;
}


/* Modified by w00176964 for VoLTE_PhaseIII ��Ŀ, 2013-12-13, end */

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccServRejRsltInd
 ��������  : �յ�SERVICE_REJECT_IND��Ϣ���͸�mscc
 �������  : enCnDomainId - ������
             usRejCause   - �ܾ�ԭ��ֵ
             enRejType    - �ܾ�����
 �������  : ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :
 �޸���ʷ      :
  1.��    ��   : 2014��4��1��
    ��    ��   : z00161729
    �޸�����   : DTS2014040300125:service ���ܺ�����detach ind������Ҫ�ϱ�^rejinfo
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccServRejRsltInd(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32  enCnDomainId,
    VOS_UINT16                          usRejCause
)
{
    MMC_MSCC_SERV_REJ_IND_STRU          *pstServReqRsltInd = VOS_NULL_PTR;

    pstServReqRsltInd = (MMC_MSCC_SERV_REJ_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_SERV_REJ_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if(VOS_NULL_PTR == pstServReqRsltInd)
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccServRejRsltInd():ERROR:Memory Alloc Error");
        return;
    }
    PS_MEM_SET(((VOS_UINT8*)pstServReqRsltInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_SERV_REJ_IND_STRU) - VOS_MSG_HEAD_LENGTH);


    /* �����Ϣͷ */
    pstServReqRsltInd->MsgHeader.ulMsgName        = ID_MMC_MSCC_SRV_REJ_IND;
    pstServReqRsltInd->MsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstServReqRsltInd->MsgHeader.ulSenderPid      = WUEPS_PID_MMC;
    pstServReqRsltInd->MsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstServReqRsltInd->MsgHeader.ulReceiverPid    = UEPS_PID_MSCC;
    pstServReqRsltInd->MsgHeader.ulLength         = sizeof(MMC_MSCC_SERV_REJ_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    /* �����Ϣ */
    pstServReqRsltInd->enCnDomainId = enCnDomainId;
    pstServReqRsltInd->usRejCause   = usRejCause;
    pstServReqRsltInd->ucOriginalRejCause = NAS_MML_GetOriginalRejectCause(pstServReqRsltInd->usRejCause);
    PS_SEND_MSG(WUEPS_PID_MMC, pstServReqRsltInd);

    return;
}



/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccUsimAuthFailInd
 ��������  : ����MSCC����ܾ�ԭ��ֵ��Ϣ
 �������  :
 �������  : ��
 �� �� ֵ  : ��
 �޸���ʷ      :
 1.��    ��   : 2013��11��15��
   ��    ��   : m00217266
   �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccUsimAuthFailInd(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32            enSrvDomain,
    NAS_MML_SIM_AUTH_FAIL_ENUM_UINT16   enRejCause
                    )
{
    MMC_MSCC_USIM_AUTH_FAIL_IND_STRU    *pstUsimAuthFailInd       = VOS_NULL_PTR;

    pstUsimAuthFailInd = (MMC_MSCC_USIM_AUTH_FAIL_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_USIM_AUTH_FAIL_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstUsimAuthFailInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccUsimAuthFailInd():ERROR:Memory Alloc Error for pstUsimAuthFailInds ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstUsimAuthFailInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_USIM_AUTH_FAIL_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣ*/
    pstUsimAuthFailInd->enCnDomainId   = enSrvDomain;
    pstUsimAuthFailInd->enRejCause     = enRejCause;

    /* �����Ϣͷ */
    pstUsimAuthFailInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_USIM_AUTH_FAIL_IND;
    pstUsimAuthFailInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstUsimAuthFailInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstUsimAuthFailInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstUsimAuthFailInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstUsimAuthFailInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_USIM_AUTH_FAIL_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstUsimAuthFailInd);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccCsServiceConnStatusInd
 ��������  : ��MSCC����csҵ����������״̬��Ϣ
 �������  : ucCsServiceConnStatusFlag - csҵ����������״̬��ʶ
 �������  : ��
 �� �� ֵ  : ��
 �޸���ʷ      :
 1.��    ��   : 2014��3��4��
   ��    ��   : z00161729
   �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccCsServiceConnStatusInd(
    VOS_UINT8                           ucCsServiceConnStatusFlag
)
{
    MMC_MSCC_CS_SERVICE_CONN_STATUS_IND_STRU    *pstCsServiceConnStatusInd = VOS_NULL_PTR;

    pstCsServiceConnStatusInd = (MMC_MSCC_CS_SERVICE_CONN_STATUS_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_CS_SERVICE_CONN_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstCsServiceConnStatusInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccCsServiceConnStatusInd():ERROR:Memory Alloc Error for pstUsimAuthFailInds ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstCsServiceConnStatusInd) + VOS_MSG_HEAD_LENGTH, 0,
               sizeof(MMC_MSCC_CS_SERVICE_CONN_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstCsServiceConnStatusInd->stMsgHeader.ulMsgName         = ID_MMC_MSCC_CS_SERVICE_CONN_STATUS_IND;
    pstCsServiceConnStatusInd->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstCsServiceConnStatusInd->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstCsServiceConnStatusInd->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstCsServiceConnStatusInd->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstCsServiceConnStatusInd->stMsgHeader.ulLength          = sizeof(MMC_MSCC_CS_SERVICE_CONN_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    /* �����Ϣ*/
    pstCsServiceConnStatusInd->ucCsServiceConnStatusFlag   = ucCsServiceConnStatusFlag;

    PS_SEND_MSG(WUEPS_PID_MMC, pstCsServiceConnStatusInd);

    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccRssiInd
 ��������  : �����ź�����
 �������  : ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��20��
   ��    ��   : zhoujun \40661
   �޸�����   : �����ɺ���
 2.��    ��   : 2011��8��11��
   ��    ��   : W00167002
   �޸�����   : ���ܾ�ȷ��ΪȡRssiNum��ֵ
 3.��    ��   : 2012��11��21��
   ��    ��   : z00161729
   �޸�����  : ֧��cerssi��nmr
 4.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
 5.��    ��   : 2014��6��4��
   ��    ��   : B00269685
   �޸�����   : �����Ƿ���Ҫ�ϱ����ж�
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccRssiInd(MSCC_MMC_SCELL_MEAS_REPORT_TYPE_UN *punMeasReportType)
{
    MMC_MSCC_RSSI_IND_STRU              *pstRssiInfoInd      = VOS_NULL_PTR;
    NAS_MML_CAMP_PLMN_INFO_STRU        *pstCampPlmnInfo     = VOS_NULL_PTR;
    VOS_UINT32                          i;

    pstRssiInfoInd = (MMC_MSCC_RSSI_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_RSSI_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstRssiInfoInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccRssiInd():ERROR:Memory Alloc Error for pstRssiInfoInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstRssiInfoInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_RSSI_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��MSCC_MMC_RSSI_INFO_STRU��Ϣ��װ */
    pstCampPlmnInfo                             = NAS_MML_GetCurrCampPlmnInfo();
    pstRssiInfoInd->usCellDlFreq = pstCampPlmnInfo->stCampCellInfo.usCellDlFreq;
    pstRssiInfoInd->usCellUlFreq = pstCampPlmnInfo->stCampCellInfo.usCellUlFreq;
    pstRssiInfoInd->sUeRfPower   = pstCampPlmnInfo->stCampCellInfo.sUeRfPower;
    pstRssiInfoInd->ucRssiNum    = pstCampPlmnInfo->stCampCellInfo.ucRssiNum;

    pstRssiInfoInd->enRat = NAS_MML_GetCurrNetRatType();

    for ( i = 0; i < pstRssiInfoInd->ucRssiNum ; i++ )
    {
        pstRssiInfoInd->astRssi[i].ucBer      = pstCampPlmnInfo->stCampCellInfo.astRssiInfo[i].ucChannalQual;
        pstRssiInfoInd->astRssi[i].sRssiValue = pstCampPlmnInfo->stCampCellInfo.astRssiInfo[i].sRssiValue;
        pstRssiInfoInd->astRssi[i].sRscpValue = pstCampPlmnInfo->stCampCellInfo.astRssiInfo[i].sRscpValue;
    }

    PS_MEM_CPY((VOS_UINT8 *)&(pstRssiInfoInd->unMeasReportType),
                   (VOS_UINT8 *)punMeasReportType,
                   sizeof(MSCC_MMC_SCELL_MEAS_REPORT_TYPE_UN));

    /* �����Ϣͷ */
    pstRssiInfoInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_RSSI_IND;
    pstRssiInfoInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstRssiInfoInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstRssiInfoInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstRssiInfoInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstRssiInfoInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_RSSI_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstRssiInfoInd);
    return;
}





#if(FEATURE_LTE == FEATURE_ON)
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccMsgLmmCellSignInfoInd
 ��������  : ��MMA����L ģ��CELL SIGN INFO REPORT IND
 �������  : ��
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2014��11��28��
   ��    ��   : W00281933
   �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID  NAS_MMC_SndMsccMsgLmmCellSignInfoInd(
    MSCC_MMC_SCELL_MEAS_REPORT_TYPE_UN  *punMeasReportType,
    MSCC_MMC_LMM_CELL_SIGN_INFO_STRU     *pstRssiValueInfo
    )
{
    MMC_MSCC_LMM_CELL_SIGN_INFO_REPORT_IND_STRU      *pstSndMsg            = VOS_NULL_PTR;                               /* ����ԭ������ָ��                         */

    pstSndMsg = (MMC_MSCC_LMM_CELL_SIGN_INFO_REPORT_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_LMM_CELL_SIGN_INFO_REPORT_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstSndMsg )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccMsgLmmCellSignInfoInd():ERROR:Memory Alloc Error for pstRssiInfoInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstSndMsg) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_LMM_CELL_SIGN_INFO_REPORT_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��MMC_MSCC_LMM_RSSI_IND_STRU��Ϣ��װ */
    pstSndMsg->stLteRssi.sRssi = pstRssiValueInfo->sRssi;
    pstSndMsg->stLteRssi.sRsd  = pstRssiValueInfo->sRsd;
    pstSndMsg->stLteRssi.sRsrp = pstRssiValueInfo->sRsrp;
    pstSndMsg->stLteRssi.sRsrq = pstRssiValueInfo->sRsrq;
    pstSndMsg->stLteRssi.lSINR = pstRssiValueInfo->lSINR;

    pstSndMsg->stLteRssi.stCQI.usRI      = pstRssiValueInfo->stCQI.usRI;
    pstSndMsg->stLteRssi.stCQI.ausCQI[0] = pstRssiValueInfo->stCQI.ausCQI[0];
    pstSndMsg->stLteRssi.stCQI.ausCQI[1] =pstRssiValueInfo->stCQI.ausCQI[1];

    PS_MEM_CPY((VOS_UINT8 *)&(pstSndMsg->unMeasReportType),
                   (VOS_UINT8 *)punMeasReportType,
                   sizeof(MSCC_MMC_SCELL_MEAS_REPORT_TYPE_UN));

    /* �����Ϣͷ */
    pstSndMsg->MsgHeader.ulMsgName         = ID_MMC_MSCC_LMM_CELL_SIGN_INFO_REPORT_IND;
    pstSndMsg->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstSndMsg->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstSndMsg->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstSndMsg->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstSndMsg->MsgHeader.ulLength          = sizeof(MMC_MSCC_LMM_CELL_SIGN_INFO_REPORT_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstSndMsg);

    return;
}

#endif

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccSysCfgCnf
 ��������  : MMC��MSCC�ϱ�syscfg���ý��
 �������  : ulRst - syscfg���ý��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��7��21��
    ��    ��   : z00161729
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��3��30��
    ��    ��   : l00167671
    �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccSysCfgCnf(
    NAS_MSCC_PIF_SYS_CFG_SET_RESULT_ENUM_UINT32                   ulRst
)
{
    MMC_MSCC_SYS_CFG_SET_CNF_STRU        *pstSyscfgSetCnf = VOS_NULL_PTR;

    pstSyscfgSetCnf = (MMC_MSCC_SYS_CFG_SET_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_SYS_CFG_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstSyscfgSetCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccSysCfgCnf():ERROR:Memory Alloc Error for pstSyscfgSetCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstSyscfgSetCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_SYS_CFG_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstSyscfgSetCnf->enRst                       = ulRst;

    /* �����Ϣͷ */
    pstSyscfgSetCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_SYS_CFG_CNF;
    pstSyscfgSetCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstSyscfgSetCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstSyscfgSetCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstSyscfgSetCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstSyscfgSetCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_SYS_CFG_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstSyscfgSetCnf);

    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccNetScanCnf
 ��������  : MMC��MSCC�ϱ�NetScan���
 �������  : pstNetScanCnf - ������ϱ��Ľ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��16��
    ��    ��   : w00242748
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccNetScanCnf(
    MMC_MSCC_NET_SCAN_CNF_STRU             *pstMmcMsccNetScanCnfMsg
)
{
    MMC_MSCC_NET_SCAN_CNF_STRU          *pstNetScanCnf       = VOS_NULL_PTR;

    pstNetScanCnf = (MMC_MSCC_NET_SCAN_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_NET_SCAN_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstNetScanCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccNetScanCnf():ERROR:Memory Alloc Error");
        return;
    }

    PS_MEM_SET( ((VOS_UINT8*)pstNetScanCnf) + VOS_MSG_HEAD_LENGTH, 0,
                sizeof(MMC_MSCC_NET_SCAN_CNF_STRU) - VOS_MSG_HEAD_LENGTH );

    /* �����Ϣͷ */
    pstNetScanCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_NET_SCAN_CNF;
    pstNetScanCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstNetScanCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstNetScanCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstNetScanCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstNetScanCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_NET_SCAN_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    pstNetScanCnf->enResult                    = pstMmcMsccNetScanCnfMsg->enResult;
    pstNetScanCnf->enCause                     = pstMmcMsccNetScanCnfMsg->enCause;
    pstNetScanCnf->ucFreqNum                   = pstMmcMsccNetScanCnfMsg->ucFreqNum;

    PS_MEM_CPY( pstNetScanCnf->astNetScanInfo,
                pstMmcMsccNetScanCnfMsg->astNetScanInfo,
                sizeof(pstNetScanCnf->astNetScanInfo) );

    PS_SEND_MSG(WUEPS_PID_MMC, pstNetScanCnf);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccAbortNetScanCnf
 ��������  : MMC��MSCC�ϱ�ֹͣNetScan���
 �������  : pstSndMsccAbortNetScanCnfMsg - ������ϱ��Ľ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��16��
    ��    ��   : w00242748
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccAbortNetScanCnf(
    MMC_MSCC_ABORT_NET_SCAN_CNF_STRU    *pstSndMsccAbortNetScanCnfMsg
)
{
    MMC_MSCC_ABORT_NET_SCAN_CNF_STRU    *pstNetScanStopCnf   = VOS_NULL_PTR;

    pstNetScanStopCnf = (MMC_MSCC_ABORT_NET_SCAN_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_ABORT_NET_SCAN_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstNetScanStopCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccAbortNetScanCnf():ERROR:Memory Alloc Error");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstNetScanStopCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_ABORT_NET_SCAN_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstNetScanStopCnf->MsgHeader.ulMsgName                  = ID_MMC_MSCC_ABORT_NET_SCAN_CNF;
    pstNetScanStopCnf->MsgHeader.ulSenderCpuId              = VOS_LOCAL_CPUID;
    pstNetScanStopCnf->MsgHeader.ulSenderPid                = WUEPS_PID_MMC;
    pstNetScanStopCnf->MsgHeader.ulReceiverCpuId            = VOS_LOCAL_CPUID;
    pstNetScanStopCnf->MsgHeader.ulReceiverPid              = UEPS_PID_MSCC;
    pstNetScanStopCnf->MsgHeader.ulLength                   = sizeof(MMC_MSCC_ABORT_NET_SCAN_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    pstNetScanStopCnf->ucFreqNum                            = pstSndMsccAbortNetScanCnfMsg->ucFreqNum;

    PS_MEM_CPY( pstNetScanStopCnf->astNetScanInfo,
                pstSndMsccAbortNetScanCnfMsg->astNetScanInfo,
                sizeof(pstNetScanStopCnf->astNetScanInfo) );


    PS_SEND_MSG(WUEPS_PID_MMC, pstNetScanStopCnf);


    return;
}



/*****************************************************************************
 �� �� ��  : NAS_Mmc_SndMsccPowerOffCnf
 ��������  : ��MSCC���͹ػ��ظ�
 �������  :
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��19��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_Mmc_SndMsccPowerOffCnf(VOS_VOID)
{
    MMC_MSCC_POWER_OFF_CNF_STRU         *pstPowerOffCnf = VOS_NULL_PTR;

    pstPowerOffCnf = (MMC_MSCC_POWER_OFF_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_POWER_OFF_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstPowerOffCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_Mmc_SndMsccPowerOffCnf():ERROR:Memory Alloc Error for pstPowerOffCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstPowerOffCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_POWER_OFF_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstPowerOffCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_POWER_OFF_CNF;

    /* �����Ϣͷ */
    pstPowerOffCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPowerOffCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPowerOffCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPowerOffCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPowerOffCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_POWER_OFF_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstPowerOffCnf);

    NAS_TRACE_HIGH("Send Msg!");

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_Mmc_SndMsccStartCnf
 ��������  : ��MSCC���Ϳ����ظ�
 �������  : ulResult - �������
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��19��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_Mmc_SndMsccStartCnf(VOS_UINT32  ulResult)
{
    MMC_MSCC_START_CNF_STRU             *pstStartCnf = VOS_NULL_PTR;

    pstStartCnf = (MMC_MSCC_START_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                      sizeof(MMC_MSCC_START_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstStartCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_Mmc_SndMsccStartCnf():ERROR:Memory Alloc Error for pstStartCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstStartCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_START_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstStartCnf->ulResult                    = ulResult;

    /* �����Ϣͷ */
    pstStartCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_START_CNF;
    pstStartCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstStartCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstStartCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstStartCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstStartCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_START_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstStartCnf);

    NAS_TRACE_HIGH("Send Msg!");

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_Mmc_SndMsccPlmnListAbortCnf
 ��������  : ��MSCC����ID_MMC_MSCC_PLMN_LIST_ABORT_CNF��Ϣ
 �������  : usSearchPlmnNum �����б��б����PLMN ID����
             pstListInfo     �����б���Ϣ
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��9��19��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
 2.��    ��   : 2011��09��21��
   ��    ��   : W00166186
   �޸�����   : V7R1 PHASE II
 3.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��

  4.��    ��   : 2013��5��30��
    ��    ��   : z00234330
    �޸�����   : DTS2013052800822,list��������Ϊ��ָ��ʱ������PIDΪ�Ƿ�,����-
                 MM_FID��λ
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccPlmnListAbortCnf(
    MMC_MSCC_PLMN_LIST_ABORT_CNF_STRU  *pstSndMsccMsg
)
{
    MMC_MSCC_PLMN_LIST_ABORT_CNF_STRU  *pstPlmnListAbortCnf = VOS_NULL_PTR;
    VOS_UINT32                           i;

    pstPlmnListAbortCnf = (MMC_MSCC_PLMN_LIST_ABORT_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                              sizeof(MMC_MSCC_PLMN_LIST_ABORT_CNF_STRU) - VOS_MSG_HEAD_LENGTH);
    if( VOS_NULL_PTR == pstPlmnListAbortCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccPlmnListAbortCnf():ERROR:Memory Alloc Error for pstPlmnListAbortCnf ");
        return;
    }

    /* �����Ϣͷ */
    PS_MEM_SET(((VOS_UINT8*)pstPlmnListAbortCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_PLMN_LIST_ABORT_CNF_STRU) - VOS_MSG_HEAD_LENGTH);
    pstPlmnListAbortCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_PLMN_LIST_ABORT_CNF;
    pstPlmnListAbortCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPlmnListAbortCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPlmnListAbortCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPlmnListAbortCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPlmnListAbortCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_PLMN_LIST_ABORT_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    /* ������������ϢΪ��ָ�����ʾ�б�Ϊ�� */
    if ( VOS_NULL_PTR == pstSndMsccMsg)
    {
        pstPlmnListAbortCnf->ulCnt = 0;

        PS_SEND_MSG(WUEPS_PID_MMC, pstPlmnListAbortCnf);

        return;
    }


    /* ת��GU��ʽ����ϢΪMSCC��ʽ�� */
    pstPlmnListAbortCnf->ulCnt  = pstSndMsccMsg->ulCnt;

    for (i =0; i<pstSndMsccMsg->ulCnt; i++)
    {
        pstPlmnListAbortCnf->aPlmnList[i].ulMcc = pstSndMsccMsg->aPlmnList[i].ulMcc;
        pstPlmnListAbortCnf->aPlmnList[i].ulMnc = pstSndMsccMsg->aPlmnList[i].ulMnc;

        pstPlmnListAbortCnf->aucPlmnStatus[i]   = pstSndMsccMsg->aucPlmnStatus[i];
        pstPlmnListAbortCnf->aucRaMode[i]       = pstSndMsccMsg->aucRaMode[i];
    }


    PS_SEND_MSG(WUEPS_PID_MMC, pstPlmnListAbortCnf);
}

/*****************************************************************************
 �� �� ��  : NAS_Mmc_SndMsccPlmnListInd
 ��������  : ��MSCC����ID_MMC_MSCC_PLMN_LIST_CNF��Ϣ
 �������  : usSearchPlmnNum �����б��б����PLMN ID����
             pstListInfo     �����б���Ϣ
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��9��19��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccPlmnListInd(
    MMC_MSCC_PLMN_LIST_CNF_STRU         *pstSndMsccMsg
)
{
    MMC_MSCC_PLMN_LIST_CNF_STRU          *pstPlmnListCnf = VOS_NULL_PTR;
    VOS_UINT32                           i;

    pstPlmnListCnf = (MMC_MSCC_PLMN_LIST_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_PLMN_LIST_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstPlmnListCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccDetachInd():ERROR:Memory Alloc Error for pstPlmnListCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstPlmnListCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_PLMN_LIST_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ת��GU��ʽ����ϢΪMSCC��ʽ�� */
    pstPlmnListCnf->ulCnt  = pstSndMsccMsg->ulCnt;

    for (i =0; i<pstSndMsccMsg->ulCnt; i++)
    {
        pstPlmnListCnf->aPlmnList[i].ulMcc = pstSndMsccMsg->aPlmnList[i].ulMcc;
        pstPlmnListCnf->aPlmnList[i].ulMnc = pstSndMsccMsg->aPlmnList[i].ulMnc;

        pstPlmnListCnf->aucPlmnStatus[i]   = pstSndMsccMsg->aucPlmnStatus[i];
        pstPlmnListCnf->aucRaMode[i]       = pstSndMsccMsg->aucRaMode[i];
    }

    /* �����Ϣͷ */
    pstPlmnListCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_PLMN_LIST_CNF;
    pstPlmnListCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPlmnListCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPlmnListCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPlmnListCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPlmnListCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_PLMN_LIST_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstPlmnListCnf);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_Mmc_SndMsccPlmnListRej
 ��������  : ��MSCC����TAFMMC_PLMN_LIST_Rej��Ϣ
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��9��19��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_Mmc_SndMsccPlmnListRej(VOS_VOID)
{
    MMC_MSCC_PLMN_LIST_REJ_STRU        *pstPlmnListRej = VOS_NULL_PTR;

    pstPlmnListRej = (MMC_MSCC_PLMN_LIST_REJ_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_PLMN_LIST_REJ_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstPlmnListRej )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_Mmc_SndMsccPlmnListRej():ERROR:Memory Alloc Error for pstPlmnListRej ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstPlmnListRej) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_PLMN_LIST_REJ_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstPlmnListRej->MsgHeader.ulMsgName         = ID_MMC_MSCC_PLMN_LIST_REJ;
    pstPlmnListRej->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPlmnListRej->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPlmnListRej->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPlmnListRej->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPlmnListRej->MsgHeader.ulLength          = sizeof(MMC_MSCC_PLMN_LIST_REJ_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstPlmnListRej);
    return;
}

/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */

/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

/*****************************************************************************
 �� �� ��  : NAS_MMC_GetOperPlmnInfoForMscc
 ��������  : �ṩOper Plmn��Ϣ��MSCC��ѯʹ��
 �������  : ��
 �������  : pstRptMsccOperList:��MSCC��ѯʹ�õ�Oper Plmn��Ϣ
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��28��
   ��    ��   : zhoujun 40661
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��4��7��
   ��    ��   : z00161729
   �޸�����   : �����ϱ�AT�������������C�˼�mma��mmc�ӿڵ���
 3.��    ��    : 2013��11��26��
   ��    ��    : s00190137
   �޸�����    : �����֧�����õ�OPLMN��չ��256��
*****************************************************************************/
VOS_VOID  NAS_MMC_GetOperPlmnInfoForMscc(
    MMC_TAF_PLMN_LIST_INFO_ST          *pstRptMsccOperList
)
{
    NAS_MML_SIM_OPERPLMN_INFO_STRU     *pstOperPlmnList = VOS_NULL_PTR;
    VOS_UINT32                          i;

    pstOperPlmnList                     = NAS_MML_GetSimOperPlmnList();

    pstRptMsccOperList->usCurPlmnNum     = pstOperPlmnList->usOperPlmnNum;

    if (pstRptMsccOperList->usCurPlmnNum > TAF_USER_MAX_PLMN_NUM)
    {
        pstRptMsccOperList->usCurPlmnNum = TAF_USER_MAX_PLMN_NUM;
    }

    for(i = 0; i < pstRptMsccOperList->usCurPlmnNum; i++)
    {
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
        PS_MEM_CPY((&(pstRptMsccOperList->astPlmnInfo[i].stPlmn)) , &(pstOperPlmnList->astOperPlmnInfo[i].stPlmnId), sizeof(NAS_MML_PLMN_ID_STRU));
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

        pstRptMsccOperList->astPlmnInfo[i].usRaMode  = pstOperPlmnList->astOperPlmnInfo[i].usSimRat;
    }
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_GetUserPlmnInfoForMscc
 ��������  : �ṩUser Plmn��Ϣ��MSCC��ѯʹ��
 �������  : ��
 �������  : pstRptMsccUserList:��MSCC��ѯʹ�õ�User Plmn��Ϣ
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��28��
   ��    ��   : zhoujun 40661
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��4��7��
   ��    ��   : z00161729
   �޸�����   : �����ϱ�AT�������������C�˼�mma��mmc�ӿڵ���
 3.��    ��    : 2013��11��26��
   ��    ��    : s00190137
   �޸�����    : �����֧�����õ�OPLMN��չ��256��
*****************************************************************************/
VOS_VOID  NAS_MMC_GetUserPlmnInfoForMscc(
    MMC_TAF_PLMN_LIST_INFO_ST          *pstRptMsccUserList
)
{
    NAS_MML_SIM_USERPLMN_INFO_STRU     *pstUserPlmnList = VOS_NULL_PTR;
    VOS_UINT32                          i;

    pstUserPlmnList                     = NAS_MML_GetSimUserPlmnList();

    pstRptMsccUserList->usCurPlmnNum     = (VOS_UINT16)pstUserPlmnList->ucUserPlmnNum;

    if (pstRptMsccUserList->usCurPlmnNum > NAS_MML_MAX_USERPLMN_NUM)
    {
        pstRptMsccUserList->usCurPlmnNum = NAS_MML_MAX_USERPLMN_NUM;
    }

    for(i = 0; i < pstRptMsccUserList->usCurPlmnNum; i++)
    {
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
        PS_MEM_CPY(&(pstRptMsccUserList->astPlmnInfo[i].stPlmn) , &(pstUserPlmnList->astUserPlmnInfo[i].stPlmnId), sizeof(MSCC_MMC_PLMN_ID_STRU));
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

        pstRptMsccUserList->astPlmnInfo[i].usRaMode  = pstUserPlmnList->astUserPlmnInfo[i].usSimRat;
    }
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_GetHPlmnInfoForMscc
 ��������  : �ṩHPlmn��Ϣ��MSCC��ѯʹ��
 �������  : ��
 �������  : pstRptMsccHplmnList:��MSCC��ѯʹ�õ�HPlmn��Ϣ
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��28��
   ��    ��   : zhoujun 40661
   �޸�����   : �����ɺ���
 2.��    ��   : 2012��8��10��
   ��    ��   : L00171473
   �޸�����   : DTS2012082204471, TQE����
 3.��    ��   : 2013��4��7��
   ��    ��   : z00161729
   �޸�����   : �����ϱ�AT�������������C�˼�mma��mmc�ӿڵ���
 4.��    ��    : 2013��11��26��
   ��    ��    : s00190137
   �޸�����    : �����֧�����õ�OPLMN��չ��256��
*****************************************************************************/
VOS_VOID  NAS_MMC_GetHPlmnInfoForMscc(
    MMC_TAF_PLMN_LIST_INFO_ST           *pstRptMsccHplmnList
)
{
    NAS_MML_SIM_HPLMN_WITH_RAT_INFO_STRU *pstHplmnWithRat = VOS_NULL_PTR;
    VOS_UINT32                            i;

    pstHplmnWithRat                     = NAS_MML_GetSimHplmnWithRatList();

    pstRptMsccHplmnList->usCurPlmnNum    = (VOS_UINT16)pstHplmnWithRat->ucHPlmnWithRatNum;

    if (pstRptMsccHplmnList->usCurPlmnNum > NAS_MML_MAX_HPLMN_WITH_RAT_NUM)
    {
        pstRptMsccHplmnList->usCurPlmnNum = NAS_MML_MAX_HPLMN_WITH_RAT_NUM;
    }

    for(i = 0; i < pstRptMsccHplmnList->usCurPlmnNum; i++)
    {
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
        PS_MEM_CPY(&(pstRptMsccHplmnList->astPlmnInfo[i].stPlmn) , &(pstHplmnWithRat->astHPlmnWithRatInfo[i].stPlmnId), sizeof(MSCC_MMC_PLMN_ID_STRU));
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

        pstRptMsccHplmnList->astPlmnInfo[i].usRaMode = pstHplmnWithRat->astHPlmnWithRatInfo[i].usSimRat;
    }

}

/*****************************************************************************
 �� �� ��  : NAS_MMC_GetSelPlmnInfoForMscc
 ��������  : �ṩSelPlmn��Ϣ��MSCC��ѯʹ��
 �������  : ��
 �������  : pstRptMsccSelPlmnList:��MSCC��ѯʹ�õ�SelPlmn��Ϣ
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��28��
   ��    ��   : zhoujun 40661
   �޸�����   : �����ɺ���
 2.��    ��   : 2011��11��30��
   ��    ��   : w00176964
   �޸�����   : ����ע��BBIT����
 3.��    ��   : 2013��4��7��
   ��    ��   : z00161729
   �޸�����   : �����ϱ�AT�������������C�˼�mma��mmc�ӿڵ���
 4.��    ��   : 2013��8��29��
   ��    ��   : w00242748
   �޸�����   : KLOC�澯����
 5.��    ��    : 2013��11��26��
   ��    ��    : s00190137
   �޸�����    : �����֧�����õ�OPLMN��չ��256��
*****************************************************************************/
VOS_VOID  NAS_MMC_GetSelPlmnInfoForMscc(
    MMC_TAF_PLMN_LIST_INFO_ST          *pstRptMsccSelPlmnList
)
{
    NAS_MML_SIM_SELPLMN_INFO_STRU      *pstSelPlmnList = VOS_NULL_PTR;
    VOS_UINT32                          i;

    pstSelPlmnList                      = NAS_MML_GetSimSelPlmnList();

    pstRptMsccSelPlmnList->usCurPlmnNum  = (VOS_UINT16)pstSelPlmnList->ucSelPlmnNum;

    if (pstRptMsccSelPlmnList->usCurPlmnNum > NAS_MML_MAX_SELPLMN_NUM)
    {
        pstRptMsccSelPlmnList->usCurPlmnNum = NAS_MML_MAX_SELPLMN_NUM;
    }

    pstRptMsccSelPlmnList->usCurPlmnNum = NAS_COMM_MIN(pstRptMsccSelPlmnList->usCurPlmnNum, NAS_MML_MAX_SELPLMN_NUM);

    for (i = 0; i <  pstRptMsccSelPlmnList->usCurPlmnNum; i++)
    {
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
        PS_MEM_CPY(&(pstRptMsccSelPlmnList->astPlmnInfo[i].stPlmn), &(pstSelPlmnList->astPlmnId[i]), sizeof(MSCC_MMC_PLMN_ID_STRU));
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

#if (FEATURE_ON == FEATURE_LTE)
        pstRptMsccSelPlmnList->astPlmnInfo[i].usRaMode   = NAS_MML_SIM_UE_SUPPORT_RAT_SUPPORT_LTE;
#else
        pstRptMsccSelPlmnList->astPlmnInfo[i].usRaMode   = NAS_MML_SIM_UE_SUPPORT_RAT;
#endif
    }

}


/*****************************************************************************
 �� �� ��  : NAS_MMC_GetServiceStatusForMscc
 ��������  : ��MMC��ǰ�ķ���״̬ת��ΪMSCC�ķ���״̬
 �������  : ucSimStatus:��ǰ����Ŀ�״̬
             enServiceStatus:��ǰ����ķ���״̬
 �������  : ��
 �� �� ֵ  : �ϱ�MSCC��ǰ����״̬
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��7��29��
   ��    ��   : zhoujun 40661
   �޸�����   : �����ɺ���
 2.��    ��   : 2012��4��27��
   ��    ��   : l00130025
   �޸�����   : DTS2012032303156:MMC�ķ���״̬���ϱ��ķ���״̬��Ҫת��
 3.��    ��   : 2015��7��24��
   ��    ��   : w00167002
   �޸�����   : DTS2015072107308:�ĵ����:����pin�룬���޸���������ʾ���Խ��н�����ҵ��
                ��Ҫ��ʾ�޷�����û���
*****************************************************************************/
NAS_MM_COM_SERVICE_STATUS_ENUM_UINT8  NAS_MMC_GetServiceStatusForMscc(
    NAS_MM_COM_SERVICE_DOMAIN_ENUM_UINT8 enSrvDomain
)
{
    NAS_MMC_SERVICE_ENUM_UINT8          enServiceStatus;

    if (NAS_MSCC_PIF_SRVDOMAIN_CS == enSrvDomain)
    {
        enServiceStatus  = NAS_MMC_GetCsServiceStatus();
    }
    else
    {
        enServiceStatus  = NAS_MMC_GetPsServiceStatus();
    }


    if ( NAS_MMC_NORMAL_SERVICE == enServiceStatus )
    {
        return MM_COM_SRVST_NORMAL_SERVICE;
    }

    if ( NAS_MMC_LIMITED_SERVICE_REGION == enServiceStatus )
    {
        return MM_COM_SRVST_LIMITED_SERVICE_REGION;
    }


    if ( NAS_MMC_LIMITED_SERVICE == enServiceStatus )
    {
        return MM_COM_SRVST_LIMITED_SERVICE;
    }

    return MM_COM_SRVST_NO_SERVICE;
}

#if ((FEATURE_ON == FEATURE_GCBS) || (FEATURE_ON == FEATURE_WCBS))
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndCbaMsgNetModInd
 ��������  : ��ǰģʽ�����仯ʱ,MSCC��Ҫ֪ͨTAFģ�鵱ǰ��
             ��ģʽ�Ա�CBSģ�鷢�ͼ����б��������
 �������  : ucNetWorkMode:��ǰ����ģʽ,0:GSM,1:WCDMA
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��8��15��
    ��    ��   : w00176964
    �޸�����   : �����ɺ���
  2.��    ��   : 2012��3��2��
    ��    ��   : l00171473
    �޸�����   : for V7R1C50 CSFB&PPAC&ETWS&ISR
  3.��    ��   : 2012��11��29��
    ��    ��   : w00176964
    �޸�����   : DTS2012042804167:���뼼��ΪLTEʱ��ʱ�ڻطŹ����в�������Ϣ
  4.��    ��   : 2013��4��7��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mmc�ӿڵ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndCbaMsgNetModInd(
    VOS_UINT8                           ucNetWorkMode
)
{
    TAFMMC_CBS_CURR_NET_MODE_IND_STRU  *pstMsg;


    if ( (ucNetWorkMode != NAS_MML_NET_RAT_TYPE_GSM)
      && (ucNetWorkMode != NAS_MML_NET_RAT_TYPE_WCDMA)
      && (ucNetWorkMode != NAS_MML_NET_RAT_TYPE_LTE) )
    {
        NAS_ERROR_LOG(WUEPS_PID_MMC, "NAS_MMC_SndCbaMsgNetModInd: NetMode ERROR");
        return;
    }


    pstMsg = (TAFMMC_CBS_CURR_NET_MODE_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                                           sizeof(TAFMMC_CBS_CURR_NET_MODE_IND_STRU));


    if( VOS_NULL_PTR == pstMsg )
    {
        PS_NAS_LOG(WUEPS_PID_MMC, VOS_NULL, PS_LOG_LEVEL_ERROR, "NAS_MMC_SndCbaMsgNetModInd:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET(pstMsg,0,sizeof(TAFMMC_CBS_CURR_NET_MODE_IND_STRU));

    pstMsg->MsgHeader.ulLength          = sizeof(TAFMMC_CBS_CURR_NET_MODE_IND_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMsg->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulReceiverPid     = WUEPS_PID_TAF;

    /* ��д��Ϣ���  */
    pstMsg->MsgHeader.ulMsgName         = TAFMMC_CBS_CURR_NET_MODE_IND;


    if ( NAS_MML_NET_RAT_TYPE_WCDMA == ucNetWorkMode)
    {
        pstMsg->ucCurNetWork            = MN_NET_MODE_WCDMA;
    }
    else if( NAS_MML_NET_RAT_TYPE_GSM == ucNetWorkMode)
    {
        pstMsg->ucCurNetWork            = MN_NET_MODE_GSM;
    }
    else if (NAS_MML_NET_RAT_TYPE_LTE == ucNetWorkMode)
    {
        pstMsg->ucCurNetWork            = MN_NET_MODE_LTE;
    }
    else
    {

    }

   PS_SEND_MSG( WUEPS_PID_MMC, pstMsg);

}



/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccMsgNoNetWorkInd
 ��������  : ֪ͨCBSģ�鵱ǰ����ģʽΪ�Ƿ�
 �������  : ��
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��10��13��
   ��    ��   : zhoujun \ 40661
   �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID  NAS_MMC_SndMsccMsgNoNetWorkInd( VOS_VOID )
{
    TAFMMC_CBS_NO_NETWORK_IND_STRU      *pstSndMsg;                               /* ����ԭ������ָ��                         */

    /*������Ϣ  */
    pstSndMsg = (TAFMMC_CBS_NO_NETWORK_IND_STRU*)PS_ALLOC_MSG_WITH_HEADER_LEN(
                                             WUEPS_PID_MMC,
                                             sizeof(TAFMMC_CBS_NO_NETWORK_IND_STRU));
    if( VOS_NULL_PTR == pstSndMsg )
    {
        PS_NAS_LOG(WUEPS_PID_MMC, VOS_NULL, PS_LOG_LEVEL_ERROR, "NAS_MMC_SndMsccMsgNoNetWorkInd:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    pstSndMsg->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstSndMsg->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstSndMsg->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstSndMsg->MsgHeader.ulReceiverPid     = WUEPS_PID_TAF;

    pstSndMsg->MsgHeader.ulMsgName   = TAFMMC_CBS_NO_NETWORK_IND;

    PS_SEND_MSG(WUEPS_PID_MMC, pstSndMsg);

    return;
}

#endif

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccSpecPlmnSearchAbortCnf
 ��������  : ��MSCC����MSCC_MMC_SPEC_PLMN_SEARCH_ABORT_CNF��Ϣ
 �������  : pstSndMsccMsg - MSCC_MMC_SPEC_PLMN_SEARCH_ABORT_CNF��Ϣ����
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2011��11��28��
   ��    ��   : z00161729
   �޸�����   : �����ɺ���
 2.��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccSpecPlmnSearchAbortCnf(VOS_VOID)
{
    /* ��MMC_MSCC_SPEC_PLMN_SEARCH_ABORT_CNF_STRU��װ��Ϣ������ */
    MMC_MSCC_SPEC_PLMN_SEARCH_ABORT_CNF_STRU                *pstSpecPlmnSrchAbortCnf = VOS_NULL_PTR;

    pstSpecPlmnSrchAbortCnf = (MMC_MSCC_SPEC_PLMN_SEARCH_ABORT_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                                  sizeof(MMC_MSCC_SPEC_PLMN_SEARCH_ABORT_CNF_STRU) - VOS_MSG_HEAD_LENGTH);
    if( VOS_NULL_PTR == pstSpecPlmnSrchAbortCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccSpecPlmnSearchAbortCnf():ERROR:Memory Alloc Error for pstSpecPlmnSrchAbortCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstSpecPlmnSrchAbortCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_SPEC_PLMN_SEARCH_ABORT_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstSpecPlmnSrchAbortCnf->MsgHeader.ulMsgName            = ID_MMC_MSCC_SPEC_PLMN_SEARCH_ABORT_CNF;
    pstSpecPlmnSrchAbortCnf->MsgHeader.ulSenderCpuId        = VOS_LOCAL_CPUID;
    pstSpecPlmnSrchAbortCnf->MsgHeader.ulSenderPid          = WUEPS_PID_MMC;
    pstSpecPlmnSrchAbortCnf->MsgHeader.ulReceiverCpuId      = VOS_LOCAL_CPUID;
    pstSpecPlmnSrchAbortCnf->MsgHeader.ulReceiverPid        = UEPS_PID_MSCC;
    pstSpecPlmnSrchAbortCnf->MsgHeader.ulLength             = sizeof(MMC_MSCC_SPEC_PLMN_SEARCH_ABORT_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstSpecPlmnSrchAbortCnf);

}
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccWCipherInfoInd
 ��������  : ��AS�ϱ���Cipher��Ϣ�ϱ���MSCC
             (D_MMC_CIPHER_INFO_IND)
 �������  : VOS_VOID   pMsgData        - ��Ϣ����(��������Ϣͷ)
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��18��
    ��    ��   : l00198894
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��3��30��
    ��    ��   : l00167671
    �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccWCipherInfoInd(
    RRMM_CIPHER_INFO_IND_STRU          *pstCipherInfoInd
)
{

    MMC_MSCC_UMTS_CIPHER_INFO_IND_STRU  *pstUmtsCipherInfoInd = VOS_NULL_PTR;

    pstUmtsCipherInfoInd = (MMC_MSCC_UMTS_CIPHER_INFO_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                               sizeof(MMC_MSCC_UMTS_CIPHER_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);
    if( VOS_NULL_PTR == pstUmtsCipherInfoInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccDetachInd():ERROR:Memory Alloc Error for pstAppMsg ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstUmtsCipherInfoInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_UMTS_CIPHER_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��MMC_MSCC_UMTS_CIPHER_INFO_IND_STRU��װ��Ϣ������ */
    pstUmtsCipherInfoInd->ucCipherAlgorForCSDomain    = pstCipherInfoInd->enCipherAlgorForCSDomain;
    pstUmtsCipherInfoInd->ucCipherAlgorForPSDomain    = pstCipherInfoInd->enCipherAlgorForPSDomain;

    /* �����Ϣͷ */
    pstUmtsCipherInfoInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_UMTS_CIPHER_INFO_IND;
    pstUmtsCipherInfoInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstUmtsCipherInfoInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstUmtsCipherInfoInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstUmtsCipherInfoInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstUmtsCipherInfoInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_UMTS_CIPHER_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstUmtsCipherInfoInd);
    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccGCipherInfoInd
 ��������  : ��GMM�ϱ���Cipher��Ϣ�ϱ���MSCC
             (D_MMC_GPRS_CIPHER_INFO_IND)
 �������  : VOS_VOID   pMsgData        - ��Ϣ����(��������Ϣͷ)
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��12��18��
    ��    ��   : l00198894
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��3��30��
    ��    ��   : l00167671
    �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccGCipherInfoInd(
    MMC_GMM_CIPHER_INFO_IND_STRU       *pstCipherInfoInd
)
{

    MMC_MSCC_GPRS_CIPHER_INFO_IND_STRU  *pstGprsCipherInfoInd = VOS_NULL_PTR;

    pstGprsCipherInfoInd = (MMC_MSCC_GPRS_CIPHER_INFO_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                               sizeof(MMC_MSCC_GPRS_CIPHER_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);
    if( VOS_NULL_PTR == pstGprsCipherInfoInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccDetachInd():ERROR:Memory Alloc Error for pstAppMsg ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstGprsCipherInfoInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_GPRS_CIPHER_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��MMC_MSCC_GPRS_CIPHER_INFO_IND_STRU��װ��Ϣ������ */
    pstGprsCipherInfoInd->ucGprsCipher                      = pstCipherInfoInd->ucGprsCipher;
    pstGprsCipherInfoInd->ucGprsCipherAlg                   = pstCipherInfoInd->ucGprsCipherAlg;

    /* �����Ϣͷ */
    pstGprsCipherInfoInd->MsgHeader.ulMsgName               = ID_MMC_MSCC_GPRS_CIPHER_INFO_IND;
    pstGprsCipherInfoInd->MsgHeader.ulSenderCpuId           = VOS_LOCAL_CPUID;
    pstGprsCipherInfoInd->MsgHeader.ulSenderPid             = WUEPS_PID_MMC;
    pstGprsCipherInfoInd->MsgHeader.ulReceiverCpuId         = VOS_LOCAL_CPUID;
    pstGprsCipherInfoInd->MsgHeader.ulReceiverPid           = UEPS_PID_MSCC;
    pstGprsCipherInfoInd->MsgHeader.ulLength                = sizeof(MMC_MSCC_GPRS_CIPHER_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstGprsCipherInfoInd);
    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccUserSpecPlmnSearchRej
 ��������  : ��MSCC�����û�ָ���Ѿܾ��Ľ��
 �������  : ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2012��10��09��
   ��    ��   : z40661
   �޸�����   : �����ɺ���
2. ��    ��   : 2013��3��30��
   ��    ��   : l00167671
   �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccUserSpecPlmnSearchRej( VOS_VOID )
{
    MMC_MSCC_PLMN_SPECIAL_SEL_REJ_STRU   *pstUserSelRej = VOS_NULL_PTR;

    pstUserSelRej = (MMC_MSCC_PLMN_SPECIAL_SEL_REJ_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_PLMN_SPECIAL_SEL_REJ_STRU) - VOS_MSG_HEAD_LENGTH);
    if( VOS_NULL_PTR == pstUserSelRej )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccUserSpecPlmnSearchRej():ERROR:Memory Alloc Error for pstUserSelRej ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstUserSelRej) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_PLMN_SPECIAL_SEL_REJ_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstUserSelRej->MsgHeader.ulMsgName                      = ID_MMC_MSCC_PLMN_SPECIAL_SEL_REJ;
    pstUserSelRej->MsgHeader.ulSenderCpuId                  = VOS_LOCAL_CPUID;
    pstUserSelRej->MsgHeader.ulSenderPid                    = WUEPS_PID_MMC;
    pstUserSelRej->MsgHeader.ulReceiverCpuId                = VOS_LOCAL_CPUID;
    pstUserSelRej->MsgHeader.ulReceiverPid                  = UEPS_PID_MSCC;
    pstUserSelRej->MsgHeader.ulLength                       = sizeof(MMC_MSCC_PLMN_SPECIAL_SEL_REJ_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstUserSelRej);
    return;
}




/* Added by w00176964 for V7R1C50_DCM�����ֹС����Ϣ�ϱ�, 2012-12-11, begin */
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccAcInfoChangeInd
 ��������  : ��MSCC����С��������Ϣ�仯ָʾ
 �������  : VOS_UINT32                          ulCnDomainId,
             NAS_MML_ACCESS_RESTRICTION_STRU    *pstPsAcInfo
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��12��11��
    ��    ��   : w00176964
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��3��30��
    ��    ��   : l00167671
    �޸�����   : �����ϱ�AT�������������C��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccAcInfoChangeInd(
    VOS_UINT32                          ulCnDomainId,
    NAS_MML_ACCESS_RESTRICTION_STRU    *pstAcInfo
)
{
    MMC_MSCC_AC_INFO_CHANGE_IND_STRU    *pstAcInfoChgInd = VOS_NULL_PTR;

    pstAcInfoChgInd = (MMC_MSCC_AC_INFO_CHANGE_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_AC_INFO_CHANGE_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstAcInfoChgInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccAcInfoChangeInd():ERROR:Memory Alloc Error for pstAcInfoChgInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstAcInfoChgInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_AC_INFO_CHANGE_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��MMC_MSCC_AC_INFO_CHANGE_IND_STRU��װ��Ϣ������ */
    pstAcInfoChgInd->enCnDomainId                           = (VOS_UINT8)ulCnDomainId;
    pstAcInfoChgInd->ucRestrictPagingRsp                    = pstAcInfo->ucRestrictPagingRsp;
    pstAcInfoChgInd->ucRestrictRegister                     = pstAcInfo->ucRestrictRegister;

    if ((VOS_TRUE == pstAcInfo->ucRestrictEmergencyService)
     && (VOS_TRUE == pstAcInfo->ucRestrictNormalService))
    {
        pstAcInfoChgInd->enCellAcType = NAS_MSCC_PIF_CELL_RESTRICTION_TYPE_ALL_SERVICE;
    }
    else if (VOS_TRUE == pstAcInfo->ucRestrictNormalService)
    {
        pstAcInfoChgInd->enCellAcType = NAS_MSCC_PIF_CELL_RESTRICTION_TYPE_NORMAL_SERVICE;
    }
    else if (VOS_TRUE == pstAcInfo->ucRestrictEmergencyService)
    {
        pstAcInfoChgInd->enCellAcType = NAS_MSCC_PIF_CELL_RESTRICTION_TYPE_EMERGENCY_SERVICE;
    }
    else
    {
        pstAcInfoChgInd->enCellAcType = NAS_MSCC_PIF_CELL_RESTRICTION_TYPE_NONE;
    }

    /* �����Ϣͷ */
    pstAcInfoChgInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_AC_INFO_CHANGE_IND;
    pstAcInfoChgInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstAcInfoChgInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstAcInfoChgInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstAcInfoChgInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstAcInfoChgInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_AC_INFO_CHANGE_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstAcInfoChgInd);

    return;
}

/* Added by w00176964 for V7R1C50_DCM�����ֹС����Ϣ�ϱ�, 2012-12-11, end */



/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccEplmnInfoInd
 ��������  : MMC��MSCC�ϱ���Чplmn��Ϣ
 �������  : pstEplmnInfo - ��Чplmn��Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��12��24��
    ��    ��   : z00161729
    �޸�����   : SVLTE֧��NCELL����

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccEplmnInfoInd(
    NAS_MML_EQUPLMN_INFO_STRU          *pstEplmnInfo
)
{
    MMC_MSCC_EPLMN_INFO_IND_STRU        *pstEplmnInfoInd = VOS_NULL_PTR;

    pstEplmnInfoInd = (MMC_MSCC_EPLMN_INFO_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_EPLMN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstEplmnInfoInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccEplmnInfoInd():ERROR:Memory Alloc Error");
        return;
    }

    PS_MEM_SET( ((VOS_UINT8*)pstEplmnInfoInd) + VOS_MSG_HEAD_LENGTH, 0,
                sizeof(MMC_MSCC_EPLMN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH );

    /* �����Ϣͷ */
    pstEplmnInfoInd->stMsgHeader.ulMsgName         = ID_MMC_MSCC_EPLMN_INFO_IND;
    pstEplmnInfoInd->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstEplmnInfoInd->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstEplmnInfoInd->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstEplmnInfoInd->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstEplmnInfoInd->stMsgHeader.ulLength          = sizeof(MMC_MSCC_EPLMN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstEplmnInfoInd->stEplmnInfo.ucEquPlmnNum    = pstEplmnInfo->ucEquPlmnNum;
    PS_MEM_CPY(pstEplmnInfoInd->stEplmnInfo.astEquPlmnAddr, pstEplmnInfo->astEquPlmnAddr,
               sizeof(pstEplmnInfoInd->stEplmnInfo.astEquPlmnAddr));

    PS_SEND_MSG(WUEPS_PID_MMC, pstEplmnInfoInd);
    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccEOPlmnSetCnf
 ��������  : ��MSCC����EOPLMN���ý��
 �������  : VOS_UINT32                          ulRst,

 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��15��
    ��    ��   : x65241
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccEOPlmnSetCnf(
    VOS_UINT32                     ulRst
)
{
    MMC_MSCC_EOPLMN_SET_CNF_STRU        *pstSPlmnSetCnf = VOS_NULL_PTR;

    pstSPlmnSetCnf = (MMC_MSCC_EOPLMN_SET_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                              sizeof(MMC_MSCC_EOPLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstSPlmnSetCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccEOPlmnSetCnf():ERROR:Memory Alloc Error for pstSPlmnSetCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstSPlmnSetCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_EOPLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH);
    pstSPlmnSetCnf->ulResult                    = ulRst;

    pstSPlmnSetCnf->MsgHeader.ulMsgName         = ID_MMC_MSCC_EOPLMN_SET_CNF;
    pstSPlmnSetCnf->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstSPlmnSetCnf->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstSPlmnSetCnf->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstSPlmnSetCnf->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstSPlmnSetCnf->MsgHeader.ulLength          = sizeof(MMC_MSCC_EOPLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstSPlmnSetCnf);
    return;

}

/* Added by y00245242 for VoLTE_PhaseI  ��Ŀ, 2013-7-13, begin */
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccNetworkCapabilityInfoInd
 ��������  : �ϱ���������������MSCC module
 �������  : pstRcvMsg -- ��Ϣ��ַ

 �������  : ��
 �� �� ֵ  : ��

 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2013��07��13��
   ��    ��   : y00245242
   �޸�����   : �����ɺ���
 2.��    ��   : 2014��5��122��
   ��    ��   : b00269685
   �޸�����   : DTS2014050604659�޸�
 3.��    ��   : 2014��6��16��
   ��    ��   : y00245242
   �޸�����   : dts2014052905705�޸�
*****************************************************************************/
VOS_VOID  NAS_MMC_SndMsccNetworkCapabilityInfoInd(
    NAS_MSCC_PIF_NW_IMS_VOICE_CAP_ENUM_UINT8                     enNwImsVoCap,
    NAS_MSCC_PIF_NW_EMC_BS_CAP_ENUM_UINT8                        enNwEmcBsCap,
    NAS_MSCC_PIF_LTE_CS_CAPBILITY_ENUM_UINT8                     enLteCsCap
)
{
    MMC_MSCC_NETWORK_CAPABILITY_INFO_IND_STRU               *pstSndMsg = VOS_NULL_PTR;

    /*������Ϣ  */
    pstSndMsg = (MMC_MSCC_NETWORK_CAPABILITY_INFO_IND_STRU*)PS_ALLOC_MSG_WITH_HEADER_LEN(
                    WUEPS_PID_MMC,
                    sizeof(MMC_MSCC_NETWORK_CAPABILITY_INFO_IND_STRU));

    if (VOS_NULL_PTR == pstSndMsg)
    {
        PS_NAS_LOG(WUEPS_PID_MMC, VOS_NULL, PS_LOG_LEVEL_ERROR, "NAS_MMC_SndMsccNetworkCapabilityInfoInd: Memory Alloc Fail!");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstSndMsg) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_NETWORK_CAPABILITY_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* fill in message header */
    pstSndMsg->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstSndMsg->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstSndMsg->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstSndMsg->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;

    /* fill in message name */
    pstSndMsg->MsgHeader.ulMsgName         = ID_MMC_MSCC_NETWORK_CAPABILITY_INFO_IND;

    /* fill in message content */
    pstSndMsg->enLteCsCap         = enLteCsCap;

    pstSndMsg->enNwImsVoCap       = enNwImsVoCap;
    pstSndMsg->enNwEmcBsCap       = enNwEmcBsCap;

    PS_SEND_MSG(WUEPS_PID_MMC, pstSndMsg);

    return;
}
/* Added by y00245242 for VoLTE_PhaseI  ��Ŀ, 2013-7-13, end */

/* Added by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-12, begin */
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccCampOnInd
 ��������  : ����MSCCפ��ָʾ
 �������  : ucCampOnFlg---�Ƿ�פ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2013��11��18��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccCampOnInd(
    VOS_UINT8                           ucCampOnFlg
)
{
    MMC_MSCC_CAMP_ON_IND_STRU_STRU      *pstCampOnInd       = VOS_NULL_PTR;

    pstCampOnInd = (MMC_MSCC_CAMP_ON_IND_STRU_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_CAMP_ON_IND_STRU_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstCampOnInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccCampOnInd():ERROR:Memory Alloc Error for pstCampOnInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstCampOnInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_CAMP_ON_IND_STRU_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstCampOnInd->MsgHeader.ulMsgName         = ID_MMC_MSCC_CAMP_ON_IND;
    pstCampOnInd->MsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstCampOnInd->MsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstCampOnInd->MsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstCampOnInd->MsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstCampOnInd->MsgHeader.ulLength          = sizeof(MMC_MSCC_CAMP_ON_IND_STRU_STRU) - VOS_MSG_HEAD_LENGTH;

    pstCampOnInd->ucCampOnFlg                 = ucCampOnFlg;

    PS_SEND_MSG(WUEPS_PID_MMC, pstCampOnInd);

    return;
}

/* Added by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-12, end */

/* Added by s00246516 for L-C��������Ŀ, 2014-02-12, Begin */
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccAcqCnf
 ��������  : ����ACQ CNF��Ϣ
 �������  : enAcqRslt--��ȡ���
             pstPlmnId--��ȡ�ɹ�ʱ��PLMN ID
             usArfcn  --��ȡ�ɹ�ʱ��Ƶ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2014��02��12��
   ��    ��   : s00246516
   �޸�����   : �����ɺ���
 2.��    ��   : 2015��7��20��
   ��    ��   : w000316404
   �޸�����   : R11Э������(LTEƵ������ֵ��չ)
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccAcqCnf(
    NAS_MSCC_PIF_ACQ_RESULT_ENUM_UINT32      enAcqRslt,
    MSCC_MMC_PLMN_ID_STRU                   *pstPlmnId,
    VOS_UINT32                               ulArfcn
)
{
    MMC_MSCC_ACQ_CNF_STRU               *pstAcqCnf = VOS_NULL_PTR;

    /* ������Ϣ�� */
    pstAcqCnf = (MMC_MSCC_ACQ_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                    sizeof(MMC_MSCC_ACQ_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstAcqCnf)
    {
        NAS_ERROR_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccAcqCnf():ERROR:Memory Alloc Error for pstAcqCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstAcqCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_ACQ_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstAcqCnf->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstAcqCnf->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstAcqCnf->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstAcqCnf->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstAcqCnf->stMsgHeader.ulLength          = sizeof(MMC_MSCC_ACQ_CNF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstAcqCnf->stMsgHeader.ulMsgName         = ID_MMC_MSCC_ACQ_CNF;

    /* �����Ϣ���� */
    pstAcqCnf->enAcqRslt                     = enAcqRslt;
    pstAcqCnf->ulArfcn                       = ulArfcn;
    pstAcqCnf->stPlmnId.ulMcc                = pstPlmnId->ulMcc;
    pstAcqCnf->stPlmnId.ulMnc                = pstPlmnId->ulMnc;
    pstAcqCnf->enPrioClass                   = NAS_MMC_GetPlmnPrioClass(pstPlmnId);

    /* ������Ϣ */
    PS_SEND_MSG(WUEPS_PID_MMC, pstAcqCnf);
    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccAcqInd
 ��������  : ����ACQ Ind��Ϣ
 �������  : enAcqRslt--��ȡ���
             pstPlmnId--��ȡ�ɹ�ʱ��PLMN ID
             usArfcn  --��ȡ�ɹ�ʱ��Ƶ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2014��02��12��
   ��    ��   : s00246516
   �޸�����   : �����ɺ���
 2.��    ��   : 2015��7��20��
   ��    ��   : w000316404
   �޸�����   : R11Э������(LTEƵ������ֵ��չ)
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccAcqInd(
    NAS_MSCC_PIF_ACQ_RESULT_ENUM_UINT32      enAcqRslt,
    MSCC_MMC_PLMN_ID_STRU               *pstPlmnId,
    VOS_UINT32                          ulArfcn
)
{
    MMC_MSCC_ACQ_IND_STRU               *pstAcqInd = VOS_NULL_PTR;

    /* ������Ϣ�� */
    pstAcqInd = (MMC_MSCC_ACQ_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                    sizeof(MMC_MSCC_ACQ_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstAcqInd)
    {
        NAS_ERROR_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccAcqInd():ERROR:Memory Alloc Error for pstAcqCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstAcqInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_ACQ_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstAcqInd->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstAcqInd->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstAcqInd->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstAcqInd->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstAcqInd->stMsgHeader.ulLength          = sizeof(MMC_MSCC_ACQ_IND_STRU) - VOS_MSG_HEAD_LENGTH;
    pstAcqInd->stMsgHeader.ulMsgName         = ID_MMC_MSCC_ACQ_IND;

    /* �����Ϣ���� */
    pstAcqInd->enAcqRslt                     = enAcqRslt;
    pstAcqInd->ulArfcn                       = ulArfcn;
    pstAcqInd->stPlmnId.ulMcc                = pstPlmnId->ulMcc;
    pstAcqInd->stPlmnId.ulMnc                = pstPlmnId->ulMnc;
    pstAcqInd->enPrioClass                   = NAS_MMC_GetPlmnPrioClass(pstPlmnId);

    /* ������Ϣ */
    PS_SEND_MSG(WUEPS_PID_MMC, pstAcqInd);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccRegCnf
 ��������  : ����Reg CNF��Ϣ
 �������  : enRegRslt--ע����
             pstPlmnId--���ע��ʱ��PLMN ID
             usArfcn  --���ע��ʱ��Ƶ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2014��02��12��
   ��    ��   : s00246516
   �޸�����   : �����ɺ���
 2.��    ��   : 2015��7��20��
   ��    ��   : w000316404
   �޸�����   : R11Э������(LTEƵ������ֵ��չ)
 3.��    ��   : 2015��08��20��
   ��    ��   : wx270776
   �޸�����   : VIA CL DTS2015031602665
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccRegCnf(
    MMC_LMM_ATTACH_CL_REG_STATUS_ENUM8  enLmmAttachClRegStatus,
    NAS_MSCC_PIF_REG_RESULT_ENUM_UINT32 enRegRslt,
    MSCC_MMC_PLMN_ID_STRU              *pstPlmnId,
    VOS_UINT32                          ulArfcn
)
{
    MMC_MSCC_REG_CNF_STRU               *pstRegCnf = VOS_NULL_PTR;

    /* ������Ϣ�� */
    pstRegCnf = (MMC_MSCC_REG_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                    sizeof(MMC_MSCC_REG_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstRegCnf)
    {
        NAS_ERROR_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccRegCnf():ERROR:Memory Alloc Error for pstRegCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstRegCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_REG_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstRegCnf->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstRegCnf->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstRegCnf->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstRegCnf->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstRegCnf->stMsgHeader.ulLength          = sizeof(MMC_MSCC_REG_CNF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstRegCnf->stMsgHeader.ulMsgName         = ID_MMC_MSCC_REG_CNF;

    /* �����Ϣ���� */
    pstRegCnf->enRegRslt                     = enRegRslt;
    pstRegCnf->ulArfcn                       = ulArfcn;
    pstRegCnf->stPlmnId.ulMcc                = pstPlmnId->ulMcc;
    pstRegCnf->stPlmnId.ulMnc                = pstPlmnId->ulMnc;
    pstRegCnf->enPrioClass                   = NAS_MMC_GetPlmnPrioClass(pstPlmnId);
    pstRegCnf->enLmmAttachClRegStatus        = enLmmAttachClRegStatus;

    /* ������Ϣ */
    PS_SEND_MSG(WUEPS_PID_MMC, pstRegCnf);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccPowerSaveCnf
 ��������  : ����Power Save CNF��Ϣ
 �������  : enCause -- power saveԭ��ֵ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2014��02��12��
   ��    ��   : s00246516
   �޸�����   : �����ɺ���
 2.��    ��   : 2015��4��27��
   ��    ��   : y00245242
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccPowerSaveCnf(
    NAS_MSCC_PIF_POWER_SAVE_RESULT_ENUM_UINT8               enCause
)
{
    MMC_MSCC_POWER_SAVE_CNF_STRU        *pstPowerSaveCnf = VOS_NULL_PTR;

    /* ������Ϣ�� */
    pstPowerSaveCnf = (MMC_MSCC_POWER_SAVE_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                    sizeof(MMC_MSCC_POWER_SAVE_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstPowerSaveCnf)
    {
        NAS_ERROR_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccPowerSaveCnf():ERROR:Memory Alloc Error for pstPowerSaveCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstPowerSaveCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_POWER_SAVE_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstPowerSaveCnf->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPowerSaveCnf->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPowerSaveCnf->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPowerSaveCnf->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPowerSaveCnf->stMsgHeader.ulLength          = sizeof(MMC_MSCC_POWER_SAVE_CNF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstPowerSaveCnf->stMsgHeader.ulMsgName         = ID_MMC_MSCC_POWER_SAVE_CNF;

    pstPowerSaveCnf->enResult                      = enCause;

    /* ������Ϣ */
    PS_SEND_MSG(WUEPS_PID_MMC, pstPowerSaveCnf);

    return;
}

/* Added by s00246516 for L-C��������Ŀ, 2014-02-12, End */

/* Add by s00217060 for K3V3 ��ģ����������, 2014-06-27, Begin */
/*lint -e958 �޸���: j00174725; */
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccPsServiceConnStatusInd
 ��������  : ��MSCC����psҵ����������״̬��Ϣ
 �������  : ucPsServiceConnStatusFlag - psҵ����������״̬��ʶ
 �������  : ��
 �� �� ֵ  : ��
 �޸���ʷ      :
 1.��    ��   : 2014��6��27��
   ��    ��   : s00217060
   �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccPsServiceConnStatusInd(
    VOS_UINT8                                       ucPsServiceConnStatusFlag,
    MSCC_MMC_PS_SIGNALING_TYPE_ENUM_UINT8           enPsSigType
)
{
    MMC_MSCC_PS_SERVICE_CONN_STATUS_IND_STRU    *pstPsServiceConnStatusInd = VOS_NULL_PTR;

    pstPsServiceConnStatusInd = (MMC_MSCC_PS_SERVICE_CONN_STATUS_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                        sizeof(MMC_MSCC_PS_SERVICE_CONN_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstPsServiceConnStatusInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccCsServiceConnStatusInd():ERROR:Memory Alloc Error for pstUsimAuthFailInds ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstPsServiceConnStatusInd) + VOS_MSG_HEAD_LENGTH, 0,
               sizeof(MMC_MSCC_PS_SERVICE_CONN_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstPsServiceConnStatusInd->stMsgHeader.ulMsgName         = ID_MMC_MSCC_PS_SERVICE_CONN_STATUS_IND;
    pstPsServiceConnStatusInd->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPsServiceConnStatusInd->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPsServiceConnStatusInd->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPsServiceConnStatusInd->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPsServiceConnStatusInd->stMsgHeader.ulLength          = sizeof(MMC_MSCC_PS_SERVICE_CONN_STATUS_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    /* �����Ϣ*/
    pstPsServiceConnStatusInd->ucPsServiceConnStatusFlag   = ucPsServiceConnStatusFlag;
    pstPsServiceConnStatusInd->enPsSigType                 = enPsSigType;

    PS_SEND_MSG(WUEPS_PID_MMC, pstPsServiceConnStatusInd);
    return;
}
/*lint +e958 �޸���: j00174725; */
/* Add by s00217060 for K3V3 ��ģ����������, 2014-06-27, End */
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccRfAvailInd
 ��������  : ��MSCC����RF��Դ�Ƿ����ָʾ
 �������  : ucRfAvail    - RF�Ƿ����
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2014��6��30��
   ��    ��   : w00176964
   �޸�����   : �½�
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccRfAvailInd(
    VOS_UINT8                           ucRfAvail
)
{
    /* ��MMC_MSCC_AREA_LOST_NO_RF_STATUS_IND_STRU��Ϣ�����װ */
    MMC_MSCC_RF_AVAILABLE_IND_STRU     *pstRfAvailInd = VOS_NULL_PTR;

    pstRfAvailInd = (MMC_MSCC_RF_AVAILABLE_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                              sizeof(MMC_MSCC_RF_AVAILABLE_IND_STRU)- VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstRfAvailInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccRfAvailInd():ERROR:Memory Alloc Error for pstServiceStatusInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstRfAvailInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_RF_AVAILABLE_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstRfAvailInd->stMsgHeader.ulMsgName           = ID_MMC_MSCC_RF_AVAILABLE_IND;
    pstRfAvailInd->stMsgHeader.ulSenderCpuId       = VOS_LOCAL_CPUID;
    pstRfAvailInd->stMsgHeader.ulSenderPid         = WUEPS_PID_MMC;
    pstRfAvailInd->stMsgHeader.ulReceiverCpuId     = VOS_LOCAL_CPUID;
    pstRfAvailInd->stMsgHeader.ulReceiverPid       = UEPS_PID_MSCC;
    pstRfAvailInd->stMsgHeader.ulLength            = sizeof(MMC_MSCC_RF_AVAILABLE_IND_STRU) - VOS_MSG_HEAD_LENGTH;
    pstRfAvailInd->ucRfAvailFlg                    = ucRfAvail;
    pstRfAvailInd->enRatType                       = NAS_MSCC_PIF_RF_AVAILABLE_RAT_TYPE_3GPP;

    PS_SEND_MSG(WUEPS_PID_MMC, pstRfAvailInd);

    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccSrchedPlmnInfo
 ��������  : ����ID_MMC_MSCC_SRCHED_PLMN_INFO_IND��Ϣ
 �������  : MSCC_MMC_SRCHED_PLMN_INFO_IND_STRU  *pstMmcSrchedPlmnINfo����PLMN info
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2014��02��12��
   ��    ��   : s00246516
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccSrchedPlmnInfo(const MMC_MSCC_SRCHED_PLMN_INFO_IND_STRU  *pstMmcSrchedPlmnINfo)
{
    MMC_MSCC_SRCHED_PLMN_INFO_IND_STRU                     *pstSrchedPlmnInfoInd = VOS_NULL_PTR;

    pstSrchedPlmnInfoInd = (MMC_MSCC_SRCHED_PLMN_INFO_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                            sizeof(MMC_MSCC_SRCHED_PLMN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstSrchedPlmnInfoInd)
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccSrchedPlmnInfo():ERROR:Memory Alloc Error for pstSrchedPlmnInfoInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstSrchedPlmnInfoInd) + VOS_MSG_HEAD_LENGTH, 0,
        sizeof(MMC_MSCC_SRCHED_PLMN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);


    /* ���ID_MMC_MSCC_SRCHED_PLMN_INFO_IND��Ϣ */
    PS_MEM_CPY(pstSrchedPlmnInfoInd,
               pstMmcSrchedPlmnINfo,
               sizeof(MMC_MSCC_SRCHED_PLMN_INFO_IND_STRU));

    /* �����Ϣͷ */
    pstSrchedPlmnInfoInd->stMsgHeader.ulMsgName         = ID_MMC_MSCC_SRCHED_PLMN_INFO_IND;
    pstSrchedPlmnInfoInd->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstSrchedPlmnInfoInd->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstSrchedPlmnInfoInd->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstSrchedPlmnInfoInd->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstSrchedPlmnInfoInd->stMsgHeader.ulLength          = sizeof(MMC_MSCC_SRCHED_PLMN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_SEND_MSG(WUEPS_PID_MMC, pstSrchedPlmnInfoInd);

    return;
}


#if(FEATURE_ON == FEATURE_DSDS)
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccSrvAcqCnf
 ��������  : ����ID_MMC_MSCC_SRV_ACQ_CNF��Ϣ
 �������  : enResult  - ��ȡ���
             enSrvType - ҵ������
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2014��06��17��
   ��    ��   : w00242748
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccSrvAcqCnf(
    NAS_MSCC_PIF_SRV_ACQ_RESULT_ENUM_UINT8   enResult
)
{
    MMC_MSCC_SRV_ACQ_CNF_STRU           *pstSrvAcqCnf = VOS_NULL_PTR;

    /* ������Ϣ�� */
    pstSrvAcqCnf = (MMC_MSCC_SRV_ACQ_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                    sizeof(MMC_MSCC_SRV_ACQ_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstSrvAcqCnf)
    {
        NAS_ERROR_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccSrvAcqCnf():ERROR:Memory Alloc Error for pstAcqCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstSrvAcqCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_SRV_ACQ_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstSrvAcqCnf->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstSrvAcqCnf->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstSrvAcqCnf->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstSrvAcqCnf->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstSrvAcqCnf->stMsgHeader.ulLength          = sizeof(MMC_MSCC_SRV_ACQ_CNF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstSrvAcqCnf->stMsgHeader.ulMsgName         = ID_MMC_MSCC_SRV_ACQ_CNF;

    /* �����Ϣ���� */
    pstSrvAcqCnf->enResult                      = enResult;

    /* ������Ϣ */
    PS_SEND_MSG(WUEPS_PID_MMC, pstSrvAcqCnf);

    return;
}



#endif
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccCFPlmnSetCnf
 ��������  : MMC��MSCC�ϱ������Ľ��
 �������  : enRegRslt
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��2��5��
   ��    ��   : f00279542
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccCFPlmnSetCnf(
    NAS_MSCC_PIF_CFPLMN_OPER_RESULT_ENUM_UINT32             enRslt
)
{
    MMC_MSCC_CFPLMN_SET_CNF_STRU       *pstCFPlmnCnf = VOS_NULL_PTR;

    pstCFPlmnCnf = (MMC_MSCC_CFPLMN_SET_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                                                   sizeof(MMC_MSCC_CFPLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH);
    if(VOS_NULL_PTR == pstCFPlmnCnf)
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccCFPlmnSetCnf:ERROR:Memory Alloc Error for pstCFPlmnCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8 *)pstCFPlmnCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_CFPLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH);


    /* �����Ϣͷ */
    pstCFPlmnCnf->stMsgHeader.ulMsgName         = ID_MMC_MSCC_CFPLMN_SET_CNF;
    pstCFPlmnCnf->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstCFPlmnCnf->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstCFPlmnCnf->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstCFPlmnCnf->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstCFPlmnCnf->stMsgHeader.ulLength          = sizeof(MMC_MSCC_CFPLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstCFPlmnCnf->enResult                      = enRslt;

    PS_SEND_MSG(WUEPS_PID_MMC, pstCFPlmnCnf);
    return;
}
/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccCFPlmnQueryCnf
 ��������  : MMC��MSCC�ϱ������Ľ��
 �������  : pstCFPlmnListCnf: ��Ϣ����
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��2��5��
   ��    ��   : f00279542
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccCFPlmnQueryCnf(
    NAS_MSCC_PIF_CFPLMN_OPER_RESULT_ENUM_UINT32             enRslt,
    NAS_MSCC_PIF_CFPLMN_LIST_STRU                          *pstCFPlmnListInfo
)
{
    MMC_MSCC_CFPLMN_QUERY_CNF_STRU     *pstCFPlmnCnf = VOS_NULL_PTR;
    VOS_UINT32                          ulLoop;

    pstCFPlmnCnf = (MMC_MSCC_CFPLMN_QUERY_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                                                     sizeof(MMC_MSCC_CFPLMN_QUERY_CNF_STRU) - VOS_MSG_HEAD_LENGTH);
    if (VOS_NULL_PTR == pstCFPlmnCnf)
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccCFPlmnQueryCnf:ERROR:Memory Alloc Error for pstCFPlmnCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8 *)pstCFPlmnCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_CFPLMN_QUERY_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstCFPlmnCnf->stMsgHeader.ulMsgName         = ID_MMC_MSCC_CFPLMN_QUERY_CNF;
    pstCFPlmnCnf->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstCFPlmnCnf->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstCFPlmnCnf->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstCFPlmnCnf->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstCFPlmnCnf->stMsgHeader.ulLength          = sizeof(MMC_MSCC_CFPLMN_QUERY_CNF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstCFPlmnCnf->enResult                      = enRslt;

    if (VOS_NULL_PTR != pstCFPlmnListInfo)
    {
        pstCFPlmnCnf->ucPlmnNum = pstCFPlmnListInfo->ucPlmnNum;
        if (pstCFPlmnListInfo->ucPlmnNum > NAS_MSCC_PIF_MAX_CFPLMN_NUM)
        {
            pstCFPlmnCnf->ucPlmnNum = NAS_MSCC_PIF_MAX_CFPLMN_NUM;
        }

        for (ulLoop = 0; ulLoop < pstCFPlmnCnf->ucPlmnNum; ulLoop++)
        {
            pstCFPlmnCnf->astPlmn[ulLoop].ulMcc = pstCFPlmnListInfo->astPlmn[ulLoop].ulMcc;
            pstCFPlmnCnf->astPlmn[ulLoop].ulMnc= pstCFPlmnListInfo->astPlmn[ulLoop].ulMnc;
        }
    }

    PS_SEND_MSG(WUEPS_PID_MMC, pstCFPlmnCnf);
    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccPrefPlmnSetCnf
 ��������  : MMC��MSCC�ϱ������Ľ��
 �������  : NAS_MSCC_PIF_PREF_PLMN_OPER_RESULT_ENUM_UINT32          enRslt
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��02��08��
   ��    ��   : y00307564
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccPrefPlmnSetCnf(
    NAS_MSCC_PIF_PREF_PLMN_OPER_RESULT_ENUM_UINT32          enRslt
)
{
    NAS_MSCC_PIF_PREF_PLMN_SET_CNF_STRU                    *pstPrefPlmnCnf  = VOS_NULL_PTR;

    pstPrefPlmnCnf = (NAS_MSCC_PIF_PREF_PLMN_SET_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(NAS_MSCC_PIF_PREF_PLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstPrefPlmnCnf )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccPrefPlmnSetCnf:ERROR:Memory Alloc Error for pstPrefPlmnCnf ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstPrefPlmnCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(NAS_MSCC_PIF_PREF_PLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstPrefPlmnCnf->stMsgHeader.ulMsgName         = ID_MMC_MSCC_PREF_PLMN_SET_CNF;
    pstPrefPlmnCnf->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPrefPlmnCnf->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPrefPlmnCnf->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPrefPlmnCnf->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPrefPlmnCnf->stMsgHeader.ulLength          = sizeof(NAS_MSCC_PIF_PREF_PLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    pstPrefPlmnCnf->enRslt                        = enRslt;

    PS_SEND_MSG(WUEPS_PID_MMC, pstPrefPlmnCnf);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccDplmnSetCnf
 ��������  : MMC��MSCC����ID_MMC_MSCC_DPLMN_SET_CNF��Ϣ
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��10��12��
    ��    ��   : n00355355
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccDplmnSetCnf(
    VOS_UINT32                         ulRslt,
    TAF_MMA_CTRL_STRU                 *pstCtrl
)
{
    MMC_MSCC_DPLMN_SET_CNF_STRU        *pstSndMsg = VOS_NULL_PTR;

    /* ������Ϣ */
    pstSndMsg = (MMC_MSCC_DPLMN_SET_CNF_STRU *)NAS_MMC_ALLOC_MSG_WITH_HDR(sizeof(MMC_MSCC_DPLMN_SET_CNF_STRU));

    if (VOS_NULL_PTR == pstSndMsg)
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccDplmnSetCnf:ERROR:Memory Alloc Error for pstMsg ");
        return;
    }

    /* �����Ϣ���� */
    NAS_MMC_CLR_MSG_ENTITY(pstSndMsg);

    /* ��д��Ϣͷ*/
    NAS_MMC_CFG_MSG_HDR(pstSndMsg,
                        UEPS_PID_MSCC,
                        ID_MMC_MSCC_DPLMN_SET_CNF,
                        sizeof(MMC_MSCC_DPLMN_SET_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��д��Ϣ����*/
    PS_MEM_CPY(&(pstSndMsg->stCtrl), pstCtrl, sizeof(TAF_MMA_CTRL_STRU));
    pstSndMsg->ulRslt = ulRslt;

    /* ��Ϣ���� */
    NAS_MMC_SEND_MSG(pstSndMsg);

    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccGetGeoCnf
 ��������  : ����ID_MMC_MSCC_GET_GEO_CNF��Ϣ
 �������  : NAS_MSCC_PIF_PLMN_ID_STRU          *pstPlmnId
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��5��23��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccGetGeoCnf(
    NAS_MSCC_PIF_PLMN_ID_STRU          *pstPlmnId
)
{
    MMC_MSCC_GET_GEO_CNF_STRU                    *pstMsg  = VOS_NULL_PTR;

    pstMsg = (MMC_MSCC_GET_GEO_CNF_STRU *)NAS_MMC_ALLOC_MSG_WITH_HDR(sizeof(MMC_MSCC_GET_GEO_CNF_STRU));

    if( VOS_NULL_PTR == pstMsg )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccGetGeoCnf:ERROR:Memory Alloc Error for pstMsg ");
        return;
    }

    /* �����Ϣ���� */
    NAS_MMC_CLR_MSG_ENTITY(pstMsg);

    /* ��д��Ϣͷ */
    NAS_MMC_CFG_MSG_HDR(pstMsg,
                        UEPS_PID_MSCC,
                        ID_MMC_MSCC_GET_GEO_CNF,
                        sizeof(MMC_MSCC_GET_GEO_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��д��Ϣ���� */
    /* PLMN ID */
    if (VOS_NULL_PTR == pstPlmnId)
    {
        pstMsg->stPlmnId.ulMcc = NAS_MML_INVALID_MCC;
        pstMsg->stPlmnId.ulMnc = NAS_MML_INVALID_MNC;
    }
    else
    {
        PS_MEM_CPY(&(pstMsg->stPlmnId), pstPlmnId, sizeof(NAS_MSCC_PIF_PLMN_ID_STRU));
    }

    NAS_MMC_SEND_MSG(pstMsg);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccStopGetGeoCnf
 ��������  : ��MSCC����ID_MMC_MSCC_STOP_GET_GEO_CNF
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��6��5��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccStopGetGeoCnf(VOS_VOID)
{
    MMC_MSCC_STOP_GET_GEO_CNF_STRU     *pstMsg  = VOS_NULL_PTR;

    pstMsg = (MMC_MSCC_STOP_GET_GEO_CNF_STRU *)NAS_MMC_ALLOC_MSG_WITH_HDR(sizeof(MMC_MSCC_STOP_GET_GEO_CNF_STRU));

    if( VOS_NULL_PTR == pstMsg )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccStopGetGeoCnf:ERROR:Memory Alloc Error for pstMsg ");
        return;
    }

    /* �����Ϣ���� */
    NAS_MMC_CLR_MSG_ENTITY(pstMsg);

    /* ��д��Ϣͷ */
    NAS_MMC_CFG_MSG_HDR(pstMsg,
                        UEPS_PID_MSCC,
                        ID_MMC_MSCC_STOP_GET_GEO_CNF,
                        sizeof(MMC_MSCC_STOP_GET_GEO_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ��д��Ϣ���� */

    NAS_MMC_SEND_MSG(pstMsg);

    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMmcUpdateUplmnNotify
 ��������  : ģ��MSCC��mmc�ϱ������Ľ��
 �������  : pstCFPlmnListCnf: ��Ϣ����
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��02��08��
   ��    ��   : y00307564
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMmcUpdateUplmnNotify( VOS_VOID )
{
    MSCC_MMC_UPDATE_UPLMN_NTF_STRU      *pstMsg = VOS_NULL_PTR;

    /* �����ڴ�  */
    pstMsg = (MSCC_MMC_UPDATE_UPLMN_NTF_STRU *)PS_ALLOC_MSG(UEPS_PID_MSCC,
                           sizeof(MSCC_MMC_UPDATE_UPLMN_NTF_STRU) - VOS_MSG_HEAD_LENGTH);

    if ( VOS_NULL_PTR == pstMsg )
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndMmcUpdateUplmnNtf:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_MMC_UPDATE_UPLMN_NTF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->MsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulReceiverPid    = WUEPS_PID_MMC;
    pstMsg->MsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->MsgHeader.ulLength         = sizeof(MSCC_MMC_UPDATE_UPLMN_NTF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->MsgHeader.ulMsgName        = ID_MSCC_MMC_UPDATE_UPLMN_NTF;

    /* ����VOS����ԭ�� */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}




VOS_VOID NAS_MMC_SndMsccBgSearchCnf(
    MMC_LMM_BG_SRCH_RLT_ENUM_UINT32  enRlst,
    VOS_UINT8                        ucHrpdSysNum,
    LMM_MMC_HRPD_SYS_STRU           *pstHrpdSysList
)
{
    MMC_MSCC_BG_SEARCH_CNF_STRU      *pstMsg = VOS_NULL_PTR;

    /* apply for memory */
    pstMsg = (MMC_MSCC_BG_SEARCH_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_BG_SEARCH_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccBgSearchCnf:ERROR:Memory Alloc Error for MMC_MSCC_BG_SEARCH_CNF_STRU ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstMsg) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_BG_SEARCH_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* fill message head */
    pstMsg->stMsgHeader.ulMsgName         = ID_MMC_MSCC_BG_SEARCH_CNF;
    pstMsg->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMsg->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength          = sizeof(MMC_MSCC_BG_SEARCH_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    /* fill bg search reseult */
    switch (enRlst)
    {
        case MMC_LMM_BG_SRCH_RLT_SUCCESS:
            pstMsg->enRslt = MSCC_MMC_BG_SRCH_RESULT_SUCCESS;
            break;
        case MMC_LMM_BG_SRCH_RLT_FAIL:
            pstMsg->enRslt = MSCC_MMC_BG_SRCH_RESULT_FAIL;
            break;
        case MMC_LMM_BG_SRCH_RLT_ABORT:
            pstMsg->enRslt = MSCC_MMC_BG_SRCH_RESULT_ABORT;
            break;
        default:
            pstMsg->enRslt = MSCC_MMC_BG_SRCH_RESULT_BUTT;
            break;
    }

    /* only LMM return success, ucHrpdSysNum is valid  */
    if (MSCC_MMC_BG_SRCH_RESULT_SUCCESS == enRlst)
    {
        if (MSCC_MMC_BG_HRPD_MAX_SYS_NUM < ucHrpdSysNum)
        {
            NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccBgSearchCnf: ucHrpdSysNum overstep the boundary");
            ucHrpdSysNum = MSCC_MMC_BG_HRPD_MAX_SYS_NUM;
        }
        pstMsg->ucHrpdSysNum              = ucHrpdSysNum;
        PS_MEM_CPY(pstMsg->astHrpdSysList, pstHrpdSysList, (ucHrpdSysNum * sizeof(LMM_MMC_HRPD_SYS_STRU)));
    }
    else
    {
        pstMsg->ucHrpdSysNum              = 0;
    }

    /* send message */
    PS_SEND_MSG(WUEPS_PID_MMC, pstMsg);

    return;
}


VOS_VOID NAS_MMC_SndMsccStopBgSearchCnf(VOS_VOID)
{
    MMC_MSCC_STOP_BG_SEARCH_CNF_STRU   *pstMsg = VOS_NULL_PTR;

    /* apply for memory */
    pstMsg = (MMC_MSCC_STOP_BG_SEARCH_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_STOP_BG_SEARCH_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccStopBgSearchCnf:ERROR:Memory Alloc Error for MMC_MSCC_STOP_BG_SEARCH_CNF_STRU ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstMsg) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_STOP_BG_SEARCH_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* fill message head */
    pstMsg->stMsgHeader.ulMsgName         = ID_MMC_MSCC_STOP_BG_SEARCH_CNF;
    pstMsg->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMsg->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength          = sizeof(MMC_MSCC_STOP_BG_SEARCH_CNF_STRU) - VOS_MSG_HEAD_LENGTH;


    /* send message */
    PS_SEND_MSG(WUEPS_PID_MMC, pstMsg);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccMmssLteUnAvailableInd
 ��������  : ��MSCC����ID_MMC_MSCC_MMSS_LTE_UNAVAILABLE_IND��Ϣ
 �������  : enReason----������ԭ��
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��4��30��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
 2.��    ��   : 2016��1��18��
   ��    ��   : w00176964
   �޸�����   : DTS2016011802320:�޸���Ϣ��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccMmssLteUnAvailableInd(
    MSCC_MMC_MMSS_LTE_UNAVIALBLE_REASON_ENUM_UINT8          enReason
)
{
    MMC_MSCC_MMSS_LTE_UNAVAILABLE_IND_STRU                 *pstMmssLteUnavailableInd = VOS_NULL_PTR;

    pstMmssLteUnavailableInd = (MMC_MSCC_MMSS_LTE_UNAVAILABLE_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                         sizeof(MMC_MSCC_MMSS_LTE_UNAVAILABLE_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if( VOS_NULL_PTR == pstMmssLteUnavailableInd )
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccMmssLteUnAvailableInd():ERROR:Memory Alloc Error for pstMmssLteUnavailableInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstMmssLteUnavailableInd) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_MMSS_LTE_UNAVAILABLE_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstMmssLteUnavailableInd->stMsgHeader.ulMsgName         = ID_MMC_MSCC_MMSS_LTE_UNAVAILABLE_IND;
    pstMmssLteUnavailableInd->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMmssLteUnavailableInd->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMmssLteUnavailableInd->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMmssLteUnavailableInd->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstMmssLteUnavailableInd->stMsgHeader.ulLength          = sizeof(MMC_MSCC_MMSS_LTE_UNAVAILABLE_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstMmssLteUnavailableInd->enReason = enReason;

    PS_SEND_MSG(WUEPS_PID_MMC, pstMmssLteUnavailableInd);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccQueryPlmnPriClassCnf
 ��������  : ��MSCC����ID_MMC_MSCC_PLMN_PRI_CLASS_QUERY_CNF��Ϣ
 �������  : pstPlmnPriClassListInfo----plmn with pri class info
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��5��4��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
 2.��    ��   : 2015��6��3��
   ��    ��   : w00176964
   �޸�����   : CDMA Iteration 12
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccQueryPlmnPriClassCnf(
    NAS_MSCC_PIF_PLMN_PRI_CLASS_LIST_INFO_STRU             *pstPlmnPriClassListInfo
)
{
    MMC_MSCC_PLMN_PRI_CLASS_QUERY_CNF_STRU                 *pstPlmnPriClassQueryCnf = VOS_NULL_PTR;

    pstPlmnPriClassQueryCnf = (MMC_MSCC_PLMN_PRI_CLASS_QUERY_CNF_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                               sizeof(MMC_MSCC_PLMN_PRI_CLASS_QUERY_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstPlmnPriClassQueryCnf)
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccQueryPlmnPriClassCnf():ERROR:Memory Alloc Error for pstRegRejPlmnSeleInd ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstPlmnPriClassQueryCnf) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_PLMN_PRI_CLASS_QUERY_CNF_STRU) - VOS_MSG_HEAD_LENGTH);

    /* �����Ϣͷ */
    pstPlmnPriClassQueryCnf->stMsgHeader.ulMsgName         = ID_MMC_MSCC_PLMN_PRI_CLASS_QUERY_CNF;
    pstPlmnPriClassQueryCnf->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstPlmnPriClassQueryCnf->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstPlmnPriClassQueryCnf->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstPlmnPriClassQueryCnf->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstPlmnPriClassQueryCnf->stMsgHeader.ulLength          = sizeof(MMC_MSCC_PLMN_PRI_CLASS_QUERY_CNF_STRU) - VOS_MSG_HEAD_LENGTH;

    PS_MEM_CPY(&pstPlmnPriClassQueryCnf->stPlmnPriClassList, pstPlmnPriClassListInfo, sizeof(NAS_MSCC_PIF_PLMN_PRI_CLASS_LIST_INFO_STRU));

    PS_SEND_MSG(WUEPS_PID_MMC, pstPlmnPriClassQueryCnf);

    return;
}


/*****************************************************************************
Function Name   :   NAS_MMC_SndMsccPrefPlmnInfoInd
Description     :   Send message MMC_MSCC_PERF_PLMN_INFO to MSCC.
Input parameters:   enPrefPlmnType----pref plmn type
Outout parameters:  VOS_VOID
Return Value    :   VOS_VOID
Modify History:
    1)  Date    :   2015-05-5
        Author  :   w00176964
        Modify content :    Create
    2)  Date    :   2015-06-19
        Author  :   w00242748
        Modify content :    DTS2015061904170: oplmn����255���󣬻ᵼ����ѭ��
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccPrefPlmnInfoInd(
    NAS_MSCC_PIF_PREF_PLMN_TYPE_ENUM_UINT8                  enPrefPlmnType
)
{
    MMC_MSCC_PREF_PLMN_INFO_IND_STRU   *pstMsg          = VOS_NULL_PTR;
    NAS_MML_SIM_EHPLMN_INFO_STRU       *pstEhplmnInfo   = VOS_NULL_PTR;
    NAS_MML_SIM_USERPLMN_INFO_STRU     *pstUplmnInfo    = VOS_NULL_PTR;
    NAS_MML_SIM_OPERPLMN_INFO_STRU     *pstOplmnInfo    = VOS_NULL_PTR;
    VOS_UINT32                          i;
    VOS_UINT32                          j;

    /* apply for memory */
    pstMsg = (MMC_MSCC_PREF_PLMN_INFO_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_PREF_PLMN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccPrefPlmnInfoInd:ERROR:Memory Alloc Error for MMC_MSCC_PREF_PLMN_INFO_IND_STRU ");
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstMsg) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_PREF_PLMN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* fill message head */
    pstMsg->stMsgHeader.ulMsgName         = ID_MMC_MSCC_PREF_PLMN_INFO_IND;
    pstMsg->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMsg->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength          = sizeof(MMC_MSCC_PREF_PLMN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    if (NAS_MSCC_PREF_PLMN_HPLMN == enPrefPlmnType)
    {
        pstEhplmnInfo = NAS_MML_GetSimEhplmnList();

        for (i = 0,j = 0; i < NAS_MML_MIN(pstEhplmnInfo->ucEhPlmnNum, NAS_MML_MAX_EHPLMN_NUM); i++)
        {
            if (VOS_TRUE == NAS_MML_IsPlmnIdValid(&pstEhplmnInfo->astEhPlmnInfo[i].stPlmnId))
            {
                pstMsg->stEhplmnInfo.astEhPlmnInfo[j].stPlmnId = pstEhplmnInfo->astEhPlmnInfo[i].stPlmnId;
                j++;
            }
        }

        pstMsg->stEhplmnInfo.ucEhPlmnNum = (VOS_UINT8)j;
        pstMsg->enPrefPlmnType           = NAS_MSCC_PREF_PLMN_HPLMN;
    }
    else if (NAS_MSCC_PREF_PLMN_UPLMN == enPrefPlmnType)
    {
        pstUplmnInfo = NAS_MML_GetSimUserPlmnList();

        for (i = 0,j = 0; i < NAS_MML_MIN(pstUplmnInfo->ucUserPlmnNum, NAS_MML_MAX_USERPLMN_NUM); i++)
        {
            if (VOS_TRUE == NAS_MML_IsPlmnIdValid(&pstUplmnInfo->astUserPlmnInfo[i].stPlmnId))
            {
                pstMsg->stUplmnInfo.astUserPlmnInfo[j].stPlmnId = pstUplmnInfo->astUserPlmnInfo[i].stPlmnId;
                j++;
            }
        }

        pstMsg->stUplmnInfo.ucUserPlmnNum = (VOS_UINT8)j;
        pstMsg->enPrefPlmnType            = NAS_MSCC_PREF_PLMN_UPLMN;
    }
    else if (NAS_MSCC_PREF_PLMN_OPLMN == enPrefPlmnType)
    {
        pstOplmnInfo = NAS_MML_GetSimOperPlmnList();

        for (i = 0,j = 0; i < NAS_MML_MIN(pstOplmnInfo->usOperPlmnNum, NAS_MML_MAX_OPERPLMN_NUM); i++)
        {
            if (VOS_TRUE == NAS_MML_IsPlmnIdValid(&pstOplmnInfo->astOperPlmnInfo[i].stPlmnId))
            {
                pstMsg->stOplmnInfo.astOperPlmnInfo[j].stPlmnId = pstOplmnInfo->astOperPlmnInfo[i].stPlmnId;
                j++;
            }
        }

        pstMsg->stOplmnInfo.usOperPlmnNum = (VOS_UINT16)j;
        pstMsg->enPrefPlmnType            = NAS_MSCC_PREF_PLMN_OPLMN;
    }
    else
    {
        NAS_WARNING_LOG(WUEPS_PID_MMC, "NAS_MMC_SndMsccPrefPlmnInfoInd:ERROR:invalid pref plmn type entered! ");
        pstMsg->enPrefPlmnType = NAS_MSCC_PREF_PLMN_TYPE_BUTT;
    }

    /* send message */
    PS_SEND_MSG(WUEPS_PID_MMC, pstMsg);

    return;
}


/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccInterSysStartInd
 ��������  : ��MSCC����ID_MMC_MSCC_INTERSYS_START_IND��Ϣ
 �������  : enInterSysCause----��ϵͳ�任ԭ��ֵ
             enOrignRatMode-----��ϵͳ�任ʱԭʼ����ģʽ
             enDestRatMode-----��ϵͳ�任����Ŀ�����ģʽ
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��11��4��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccInterSysStartInd(
    NAS_MSCC_PIF_INTERSYS_CAUSE_ENUM_UINT32                 enInterSysCause,
    VOS_RATMODE_ENUM_UINT32                                 enOrignRatMode,
    VOS_RATMODE_ENUM_UINT32                                 enDestRatMode
)
{
    MMC_MSCC_INTERSYS_START_IND_STRU   *pstMsg = VOS_NULL_PTR;

    /* apply for memory */
    pstMsg = (MMC_MSCC_INTERSYS_START_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_INTERSYS_START_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstMsg) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_INTERSYS_START_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* fill message head */
    pstMsg->stMsgHeader.ulMsgName         = ID_MMC_MSCC_INTERSYS_START_IND;
    pstMsg->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMsg->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength          = sizeof(MMC_MSCC_INTERSYS_START_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstMsg->enInterSysCause = enInterSysCause;
    pstMsg->enOrignRatMode  = enOrignRatMode;
    pstMsg->enDestRatMode   = enDestRatMode;

    /* send message */
    PS_SEND_MSG(WUEPS_PID_MMC, pstMsg);

    return;
}

/*****************************************************************************
 �� �� ��  : NAS_MMC_SndMsccInterSysEndInd
 ��������  : ��MSCC����ID_MMC_MSCC_INTERSYS_END_IND��Ϣ
 �������  : enCampedRatMode----��ǰפ������ģʽ
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2015��11��4��
   ��    ��   : w00176964
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_MMC_SndMsccInterSysEndInd(
    VOS_RATMODE_ENUM_UINT32             enCurrRatMode
)
{
    MMC_MSCC_INTERSYS_END_IND_STRU   *pstMsg = VOS_NULL_PTR;

    /* apply for memory */
    pstMsg = (MMC_MSCC_INTERSYS_END_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMC,
                          sizeof(MMC_MSCC_INTERSYS_END_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        return;
    }

    PS_MEM_SET(((VOS_UINT8*)pstMsg) + VOS_MSG_HEAD_LENGTH, 0, sizeof(MMC_MSCC_INTERSYS_END_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    /* fill message head */
    pstMsg->stMsgHeader.ulMsgName         = ID_MMC_MSCC_INTERSYS_END_IND;
    pstMsg->stMsgHeader.ulSenderCpuId     = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid       = WUEPS_PID_MMC;
    pstMsg->stMsgHeader.ulReceiverCpuId   = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid     = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength          = sizeof(MMC_MSCC_INTERSYS_END_IND_STRU) - VOS_MSG_HEAD_LENGTH;

    pstMsg->enCurrRatMode = enCurrRatMode;

    /* send message */
    PS_SEND_MSG(WUEPS_PID_MMC, pstMsg);

    return;
}

/*lint -restore */


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif


