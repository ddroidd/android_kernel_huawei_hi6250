#ifndef  __STATUS_H__
#define  __STATUS_H__

/*===========================================================================*/

/*****************************************************************************/
/*  Copyright (C), 2004-2005, Huawei Tech. Co., Ltd.                         */
/*                                                                           */
/*  FileName: status.h                                                       */
/*                                                                           */
/*  Author:   Roger     Version :   1.00     Date:  2005.3.30                */
/*                                                                           */
/*  Description:      ģ������                                             */
/*    MAPS1000 STATUS ģ���ڲ��ӿ�ͷ�ļ�                                     */
/*                                                                           */
/*  Version:          �汾��Ϣ                                             */
/*    MAPS1000 V100R001                                                      */
/*                                                                           */
/*  Function List:    ��Ҫ�������书��                                     */
/*                                                                           */
/*  History:          ��ʷ�޸ļ�¼                                         */
/*      <author>  <time>   <version >   <desc>                               */
/*      Roger    05/03/30     1.0     build this file                        */
/*      liuyang  05/10/07     1.1     add attach & detach funcation                                                                    */
/*  jiangliping  06/08/09     1.1     A32D03479����PC����ʵ��ʱ��#pragma pack(0)��#pragma pack()�ӱ��뿪��                             */
/*    1.��    ��   : 2006��11��2��
        ��    ��   : sunxibo id:46746
        �޸�����   : �������ⵥ�ţ�A32D06406
      2.��    ��   : 2007��07��21��
        ��    ��   : l60022475
        �޸�����   : A32D12535,del Sta_UsimDetachPreproc
      3.��    ��   : 2008��3��17��
        ��    ��   : s46746
        �޸�����   : ���ⵥ��:AT2D02570,NAS B005�汾�����������
      4.��    ��   : 2008��8��05��
        ��    ��   : s46746
        �޸�����   : ���ⵥ�ţ�AT2D04712���޸�SYSINFO�ϱ�HSPA״̬
      5.��    ��   : 2008��12��20��
        ��    ��   : l65478,l00130025
        �޸�����   : ���ⵥ�ţ�AT2D07555��AT2D07488,ָ����������������˫ģ����������ע���������ϱ��������
      6.��    ��   : 2009��01��05��
        ��    ��   : l00130025
        �޸�����   : �������ⵥAT2D07968,˫ģ�б��������,����״̬�жϺ��������
      7.��    ��   : 2009��03��26��
        ��    ��   : l00130025
        �޸�����   : ���ⵥ�ţ�AT2D10349/AT2D10492,MSCC/MMA֮�佻����SYSCFG�ظ���Ϣ���˸�VOS_HEADER
      8. ��    ��   : 2009��07��07��
         ��    ��   : h44270
         �޸�����   : ���ⵥ�ţ�AT2D12792��������ʾEGPRSС����Ϣ
      9. ��    ��   : 2011��04��23��
         ��    ��   : L00171473
         �޸�����   : for V7R1 porting, ȥ��BUTT��Ķ��ţ��������WARNING
*******************************************************************************/


/******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*=================================================================*/
/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
/* ɾ��ExtAppMsccInterface.h*/
/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-3-30, begin */
#include "MmaMsccInterface.h"
#include "TafAppMma.h"
#include "TafSdcLib.h"

/* Deleted by z00161729 for V9R1 STK����, 2013-7-24, begin */

/* Deleted by z00161729 for V9R1 STK����, 2013-7-24, end */

/* Modified by z00161729 for V9R1 STK����, 2013-7-24, begin */
#include "NasStkInterface.h"
/* Modified by z00161729 for V9R1 STK����, 2013-7-24, end */
#include "TafMmaCtx.h"

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-3-30, end */


#pragma pack(4)
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*---------------  STATUS�ڲ�ʹ�ó������� ---------------*/
/*=======================================================*/
/*-----------------  ������־����  ------------*/
/* ���ʱ����*/
#define STA_TIMER_MAX                   2

/* ��Ч����״̬������ */
#define STA_FSMSUB_INDEX_NULL           2

/*---------- �ڲ�����������̵ı�ʶ  ----------*/
/* ATTACH����Ԥָ�����ڲ���ʶ */
#define STA_OPID_ATTATCH                255

/* RESTART����Ԥָ�����ڲ���ʶ */
#define STA_OPID_START                  255

/* �ڲ��������ʹ�õĹ�����ʶ */
#define STA_OPID_INSIDE                 255

/* TAFM�����߷���������̵���С��ʶ */
#define STA_OPID_MIN                    0

/* TAFM�����߷���������̵�����ʶ */
#define STA_OPID_MAX                    127

/* TAFM�����߷���������̵���ЧOpId��ʾ */
#define STA_OPID_INVALID                200

/*-------------  ��������ֵ����  --------------*/
#define STA_SUCCESS                     0
#define STA_ERROR                       1

#define STA_TRUE                        1
#define STA_FALSE                       0

/*-------- Sta_UpdateFsmFlag ���ͺ�ֵ ---------*/
#define STA_UPDATE_MONO                 0
#define STA_UPDATE_MONO_CLEAR           1
#define STA_UPDATE_DUAL                 2
#define STA_UPDATE_DUAL_CLEAR           3
#define STA_UPDATE_SINGL                4
#define STA_UPDATE_SINGL_CLEAR          5
#define STA_UPDATE_SETNEW               6

/*=======================================================*/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*--------------- STATUS�ڲ�ʹ�ú��������---------------*/
/*=======================================================*/
/*----------       �ϲ�����32����    ----------*/
/* A��Bƴ��32λ���ͣ�Aռ��16λ��Bռ��16λ */
#ifndef MMA_MAKELPARAM
#define MMA_MAKELPARAM(A,B)     ((VOS_UINT32)((VOS_UINT32)((VOS_UINT32)(A)<<16) \
                                + (VOS_UINT32)(B)))
#endif
/*----------      ȡ�õ�16λ������   ----------*/
#ifndef MMA_LOWORD
#define MMA_LOWORD(A)           (VOS_UINT16)(A)
#endif
/*----------    ȡ�ø�16λ������     ----------*/
#ifndef MMA_HIWORD
#define MMA_HIWORD(A)           (VOS_UINT16)((VOS_UINT32)(A)>>16)
#endif
/*----------    ��ӡ���ٵ�����Ϣ     ----------*/
#define STA_TRACE( PrintLevel, Str )  MMA_LOG(PrintLevel, Str )
#define STA_TRACE1( PrintLevel, Str, Para) MMA_LOG1(PrintLevel, Str, Para)

/*=======================================================*/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*------------- STATUS�ڲ�ȫ�����ݽṹ����  -------------*/
/*=======================================================*/

/*----------- CS��PS�����״̬��ֵ  -----------*/
#define STA_SRVC_NORMAL_SERVICE_D       0
#define STA_SRVC_LIMITED_SERVICE_D      1
#define STA_SRVC_ATTEMPTING_TO_UPDATE_D 2
#define STA_SRVC_NO_IMSI_D              3
#define STA_SRVC_NO_SERVICE_D           4
#define STA_SRVC_DETACH_D               5
#define STA_SRVC_DISABLE_D              6

#define STA_SAT_SERVICE_CHANGE          0
#define STA_SAT_LOCINFO_CHANGE          1

#define STA_SAT_LOCATION_NORMAL_SERVICE 0
#define STA_SAT_LOCATION_LIMIT_SERVICE  1
#define STA_SAT_LOCATION_NO_SERVICE     2

#define STA_SAT_LOCATION_INFORMATON_LEN 7

/*------------   �¼��������ͺ�    ------------*/
#define STA_OP_NULL                     0X000
#define STA_OP_REGPLMN                  0X001
#define STA_OP_CSSERVICESTATUS          0X002
#define STA_OP_PSSERVICESTATUS          0X004
#define STA_OP_PLMNLIST                 0X008
#define STA_OP_PLMNRESELMODE            0X010
#define STA_OP_PHONEERROR               0X020
#define STA_OP_PHONESERVICESTATUS       0X040    /* AT^SRVST */
#define STA_OP_SPARE                    0X100

/*----------- �ڲ�FSM��״̬��ʶ��  ------------*/
#define STA_FSM_INVALID                 0X0000
#define STA_FSM_NULL                    0X0001
#define STA_FSM_ENABLE                  0X0002
#define STA_FSM_RESTART                 0X0004
#define STA_FSM_STOP                    0X0008

#define STA_FSM_PLMN_LIST               0X0040
#define STA_FSM_PLMN_RESEL              0X0080
#define STA_FSM_PLMN_SEL                0X0100
/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-26, begin */

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-26, end */
/* �����״̬�����Ķ�ʱ������ */
#define STA_FSM_TIMER_CLEAR             0X1001
/* ���ı䵱ǰ״̬��־ */
#define STA_FSM_NO_UPDATE               0X1002

/*------------ �ڲ�FSM��״̬��ʶ�� ------------*/
#define STA_FSMSUB_NULL                 0X00    /* ����״̬*/
#define STA_FSMSUB_OK                   0X10    /* ʹ��״̬*/
#define STA_FSMSUB_MONO                 0X20    /* ֻ�е�һ����״̬*/
#define STA_FSMSUB_PLMN_RESEL_AUTO      0X05    /* PLMN_RESEL��״̬,�Զ� */
#define STA_FSMSUB_PLMN_RESEL_MANUAL    0X06    /* PLMN_RESEL��״̬,�ֶ� */

#define STA_TIMER_NULL_LEN                  (100)     /* ��λms */
#define STA_TIMER_RESTART_LEN               (70000)   /* ��λms */
#define STA_TIMER_STOP_LEN                  (60000)   /* ��λms */
#define STA_TIMER_GUL_PLMN_LIST_LEN         (238000)  /* ��λms */
#define STA_TIMER_GU_PLMN_LIST_LEN          (118000)  /* ��λms */
#define STA_TIMER_PLMN_RESEL_LEN            (320000)  /* ��λms */
#define STA_TIMER_PLMN_SEL_LEN              (110000)  /* ��λms */
#define STA_TIMER_SERVICE_IND_LEN           (10000)   /* ��λms */
#define STA_TIMER_SPEC_PLMN_ABORT_LEN       (5000)    /* ��λms */
#define STA_TIMER_GUL_PLMN_LIST_ABORT_LEN   (10000)   /* ��λms */
#define STA_TIMER_GU_PLMN_LIST_ABORT_LEN    (5000)    /* ��λms */

/*------------ FSM״̬����ʱ������ ------------*/
typedef enum
{
    STA_TIMER_NULL                      = 0,
    STA_TIMER_PLMN_LIST,
    STA_TIMER_PLMN_RESEL,
    STA_TIMER_PLMN_SEL,
    STA_TIMER_SERVICE_IND,/* ��ָ��ѡ��ʱ���ȴ�MSCC�ķ���״̬�ϱ�������ʱ�� */
    /* ָ������STA_TIMER_PLMN_SEL��ʱ����ʱ��
       MMA����D_MSCC_SPEC_PLMN_SEARCH_ABORT_REQ������������ʱ��10s �ղ���MSCC��
       D_MSCC_SPEC_PLMN_SEARCH_ABORT_CNF,ֱ�Ӹ�AT�ظ�ʧ�� */
    STA_TIMER_SPEC_PLMN_ABORT,

    /* list����STA_TIMER_PLMN_LIST��ʱ����ʱ��
       MMA����D_MSCC_PLMN_LIST_ABORT_REQ������������ʱ��10s �ղ���MSCC��
       D_MSCC_PLMN_LIST_ABORT_CNF,ֱ�Ӹ�AT�ظ�ʧ�� */
    STA_TIMER_PLMN_LIST_ABORT,
    STA_TIMER_BUTT
} STA_TIMER_NAME_E;

/*--------- FSM״̬��״̬�����ṹ���� ---------*/
typedef struct
{
    VOS_UINT32  ulOpId;                     /* ��ǰ״̬����������̵ı�ʶ��*/
    VOS_UINT8   ucFsmStateSub;              /* ״̬����״ֵ̬*/

    /*��¼��ǰ STATUS��ʱ��״̬*/
    STA_TIMER_NAME_E  TimerName;        /* FSM״̬������ʱ������*/
} STA_FSM_SUB_S;

typedef enum
{
    STA_DATA_TRANSFER_EDGE,
    STA_DATA_TRANSFER_R99_ONLY,
    STA_DATA_TRANSFER_HSDPA,
    STA_DATA_TRANSFER_HSUPA,
    STA_DATA_TRANSFER_HSDPA_AND_HSUPA,
    STA_DATA_TRANSFER_HSPA_PLUS,
    /* Modified by z40661 for V7R1 ��� , 2012-02-20, begin */
    STA_DATA_TRANSFER_LTE_DATA,
    STA_DATA_TRANSFER_LTE_IDLE,
    /* Modified by z40661 for V7R1 ��� , 2012-02-20, end */
    STA_DATA_TRANSFER_DC_HSPA_PLUS,
    STA_DATA_TRANSFER_DC_MIMO,
    STA_DATA_TRANSFER_MODE_BUTT
} STA_DATA_TRANSFER_MODE;

typedef VOS_UINT8 STA_DATA_TRANSFER_MODE_UINT8;

typedef enum
{
    STA_DATA_TRANSFER_PDP_DEACT,
    STA_DATA_TRANSFER_PDP_ACT,
    STA_DATA_TRANSFER_STATUS_BUTT
} STA_DATA_TRANSFER_STATUS;

typedef VOS_UINT8 STA_DATA_TRANSFER_STATUS_UINT8;


typedef VOS_UINT8 STA_USER_SPECIFY_PLMN_PROC_CTRL_ENUM_UINT8;

/*****************************************************************************
ö����    : TAF_MMA_PLMN_MODE_ENUM
ö��˵��  : ��¼6F15�ļ���PLMN MODEλ

  1.��    ��   : 2012��6��13��
    ��    ��   : ³��/l60609
    �޸�����   : ������
*****************************************************************************/
enum TAF_MMA_PLMN_MODE_ENUM
{
    TAF_MMA_PLMN_MODE_ENUM_DISABLE,
    TAF_MMA_PLMN_MODE_ENUM_ENABLE,
    TAF_MMA_PLMN_MODE_ENUM_BUTT
};
typedef VOS_UINT8 TAF_MMA_PLMN_MODE_ENUM_UINT8;

/*****************************************************************************
ö����    : TAF_MMA_AUTO_PLMN_SEL_USER_ENUM
ö��˵��  : ��¼����AT������Զ���������6F15�ļ�refresh�������Զ�����

  1.��    ��   : 2012��6��13��
    ��    ��   : ³��/l60609
    �޸�����   : ������
*****************************************************************************/
enum TAF_MMA_AUTO_PLMN_SEL_USER_ENUM
{
    TAF_MMA_AUTO_PLMN_SEL_USER_AT,
    TAF_MMA_AUTO_PLMN_SEL_USER_USIM_REFRESH,
    TAF_MMA_AUTO_PLMN_SEL_USER_BUTT
};
typedef VOS_UINT8 TAF_MMA_AUTO_PLMN_SEL_USER_ENUM_UINT8;

/*****************************************************************************
 ö����    : TAF_MMA_RAT_MODE_ENUM_U8
 ö��˵��  : MSCC��ǰ�ķ���״̬

  1.��    ��   : 2012��6��21��
    ��    ��   : l60609
    �޸�����   : AT&T&DCM:��¼4F36�ļ���RAT MODEֵ
*****************************************************************************/
enum TAF_MMA_RAT_MODE_ENUM
{
    TAF_MMA_RAT_MODE_ENUM_DAUL_MODE,
    TAF_MMA_RAT_MODE_ENUM_2G_ONLY,
    TAF_MMA_RAT_MODE_ENUM_3G_ONLY,
    TAF_MMA_RAT_MODE_ENUM_TRI_MODE,
    TAF_MMA_RAT_MODE_ENUM_LTE_ONLY,
    TAF_MMA_RAT_MODE_ENUM_BUTT          = 0xFF
};
typedef VOS_UINT8 TAF_MMA_RAT_MODE_ENUM_U8;


/*****************************************************************************
 ö����    : TAF_MMA_CS_DOMAIN_CAPA_CHANGE_TYPE_ENUM
 �ṹ˵��  : CS�������仯���͵�ö��
 1.��    ��   : 2013��6��11��
   ��    ��   : s00217060
   �޸�����   : �½�
*****************************************************************************/
enum TAF_MMA_CS_DOMAIN_CAPA_CHANGE_TYPE_ENUM
{
    TAF_MMA_CS_DOMAIN_CAPA_NO_CHANGE                        = 0,                /* CS�������ޱ仯 */
    TAF_MMA_CS_DOMAIN_CAPA_UNAVAIL_TO_AVAIL                 = 1,                /* CS���ɲ����õ����� */
    TAF_MMA_CS_DOMAIN_CAPA_AVAIL_TO_UNAVAIL                 = 2,                /* CS���ɿ��õ������� */
    TAF_MMA_CS_DOMAIN_CAPA_CHANGE_TYPE_BUTT
};
typedef VOS_UINT8 TAF_MMA_CS_DOMAIN_CAPA_CHANGE_TYPE_ENUM_UINT8;



typedef struct MMA_TIMER
{
    HTIMER       MmaHTimer;
    VOS_UINT32   ulTimerId;
    VOS_UINT8    ucTimerStatus;
}MMA_TIMER_ST;

#define     MMA_TIMER_STOP  0
#define     MMA_TIMER_RUN   1
#define     MMA_TIMER_ERROR 2

/*****************************************************************************
 �ṹ��    : TAF_MMA_NETWORK_SELECTION_MENU_CTX_STRU
 �ṹ˵��  : ����ѡ��˵�����������
 1.��    ��   : 2012��6��18��
   ��    ��   : l60609
   �޸�����   : AT&T&DCM�½�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                   ucNetSelMenuFlg;                /* ����ѡ��˵������ʶ��VOS_TRUE��ʾ���VOS_FALSE��ʾδ���� */
    TAF_MMA_PLMN_MODE_ENUM_UINT8                enPlmnMode;                     /* ��¼6F15�ļ���PLMN MODEλ */
    TAF_MMA_AUTO_PLMN_SEL_USER_ENUM_UINT8       enAutoPlmnSelUser;              /* ��¼����AT������Զ���������refresh�������Զ�������Ĭ��ΪAT */
    VOS_UINT8                                   ucRsv;                          /* ���� */
    MMA_TIMER_ST                                stTiPeriodTryingNetSelMenu;     /* ����ѡ��˵����������Գ����Զ�ѡ����ʱ�� */
}TAF_MMA_NETWORK_SELECTION_MENU_CTX_STRU;

/*****************************************************************************
 �ṹ��    : TAF_MMA_RAT_BALANCING_CTX_STRU
 �ṹ˵��  : ���뼼��ƽ�����������
 1.��    ��   : 2012��6��18��
   ��    ��   : l60609
   �޸�����   : AT&T&DCM�½�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                   ucRatBalancingFlg;              /* ���뼼��ƽ�⼤���ʶ��VOS_TRUE��ʾ���VOS_FALSE��ʾδ���� */
    TAF_MMA_RAT_MODE_ENUM_U8                    enRatMode;                      /* ��¼4F36�ļ���RAT MODE */
    VOS_UINT8                                   aucRsv[2];                          /* ���� */
    MMA_TIMER_ST                                stTiPeriodTryingRatBalancing;   /* ���뼼��ƽ����������Գ����Զ�ѡ����ʱ�� */
}TAF_MMA_RAT_BALANCING_CTX_STRU;


/*****************************************************************************
 �ṹ��    : STATUS_CONTEXT_STRU
 �ṹ˵��  : STATUS�ڲ�״̬��ȫ�ֱ�����Ϣ
 1.��    ��   : 2011��7��11��
   ��    ��   : z00161729
   �޸�����   : ���ӽ���ģʽ���ȼ�stRatPrioList,ɾ��ԭucModeAccess��ucPlmnPrio
 2.��    ��   : 2012��6��12��
   ��    ��   : l60609
   �޸�����   : ����ucNetSelMenuFlg�����ڱ�������ѡ��˵����ƹ����Ƿ񼤻�

*****************************************************************************/

/*--------- STATUS_CONTEXT_STRU�ṹ���� -------*/
typedef struct
{
    VOS_UINT32          ulFsmState;                     /* STATUS�ڲ�״̬����־λ */

    VOS_UINT32          ulPreFsmState;

    /* ״̬����״̬������ */
    STA_FSM_SUB_S       aFsmSub[STA_TIMER_MAX];         /* ״̬����ǰ״̬����Ϣ��¼*/

    VOS_UINT8           aucFsmSubFlag[STA_TIMER_MAX];   /* ��״̬��ʶ*/
    HTIMER              ahStaTimer[STA_TIMER_MAX];      /* ��ʱ������*/

    /* STATUSϵͳ״̬��¼*/
    VOS_UINT32          ulCurOpId;                      /* ��ǰЭ��ջ��Ӧ�Ĳ�����ʶ*/
    VOS_UINT32          ulCurClientId;                  /* ��ǰ�ͻ��˱�ʶ*/
    VOS_UINT32          ulNewOpId;                      /* ������Ĳ�����ʶ*/

    VOS_UINT8           ucIsReportedLocStatus;          /* ��¼�������Ƿ񱨹�STK Location Status Event */
    VOS_UINT8           ucReserve1;

    /* STATUSҵ����Ϣ��¼*/
    TAF_PLMN_ID_STRU    StaPlmnId;                      /* ָ����PLMN*/
    TAF_PLMN_LIST_STRU  PlmnList;                       /* PLMN LIST���*/
    VOS_UINT8           ucPlmnListAbortProc;           /* Plmn List Abort�������� */
    VOS_UINT8           aucReserv[3];

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, begin */
    VOS_UINT32          ulMmProc;                       /* MSCC��������*/
    VOS_UINT32          ulCsCause;                      /* CS��ԭ��ֵ */
    VOS_UINT32          ulPsCause;                      /* PS��ԭ��ֵ */
    VOS_UINT32          ulTimMaxFlg;                    /* Availabe Plmn Search Timer�Ƿ�ﵽ���ֵ */
    VOS_UINT8           ucReselMode;                    /* PLMN ��ѡ��ʽ */
    VOS_UINT8           ucOperateType;                  /* �¼��������� */
    VOS_UINT8           ucDomainFlag;                   /* ����Ч�ı�־λ*/
    VOS_UINT8           ucModeService;                  /* ע�������ģʽ���� */

    TAF_MMA_RAT_ORDER_STRU              stRatPrioList;   /* ����ģʽ���ȼ�*/

    TAF_ERROR_CODE_ENUM_UINT32          PhoneError;                     /* �����¼�����*/

    VOS_UINT8                                   aucStaPhoneOperator[STA_TIMER_MAX];
    STA_DATA_TRANSFER_STATUS_UINT8              ucDataTranStatus;                           /* ��¼С������״̬*/
    STA_DATA_TRANSFER_MODE_UINT8                ucDataTranMode;                             /* ��¼С������״̬�µ�ϵͳ��ģʽ */
    VOS_UINT8                                   ucPlmnSelMode;                  /* ��¼����ģʽ:�ֶ����Զ� */
    VOS_UINT8                                   ucPreUtranMode;                 /* ��¼��ǰ��UtranMode��FDD��TDD */
    VOS_UINT8                                   aucRes[2];
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, end */
    TAF_MMA_NETWORK_SELECTION_MENU_CTX_STRU     stNetSelMenuCtx;                /* ����ѡ��˵����������� */
    TAF_MMA_RAT_BALANCING_CTX_STRU              stRatBalancingCtx;              /* ���뼼��ƽ����������� */
} STATUS_CONTEXT_STRU;

/*=======================================================*/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*------------ Sta_UpdateData�����ӿڲ����ṹ------------*/
/*=======================================================*/
/*----------   ��״̬���²�������    ----------*/
#define     STA_FSMSUB_NEW      0X01    /* �����µ���״̬*/
#define     STA_FSMSUB_UPDATE   0X02    /* ���µ�ǰ��״̬����*/
#define     STA_FSMSUB_FINISH   0X03    /* ������״̬ */

/*---------- STA_PHONE_DATA_S�ṹ����----------*/
typedef struct
{
    VOS_UINT32  ulOpId;                     /* ������ʶ��*/
    VOS_UINT32  ulFsmState;                 /* STATUS�ڲ�״̬����־λ */
    VOS_UINT8   ucFsmStateSub;              /* ״̬����״ֵ̬*/
    VOS_UINT8   ucFsmSubOperate;            /* ���²������� */
    VOS_UINT8   ucFsmUpdateFlag;            /* ��־���µ����� */
    /* STATUSҵ����Ϣ��¼*/
    TAF_PLMN_ID_STRU   PlmnId;          /* ָ����PLMN*/
    VOS_UINT32  ulMmProc;                   /* ��ӦMM��������*/
    VOS_UINT32  ulCsServiceStatus;          /* CS�����״̬*/
    VOS_UINT32  ulPsServiceStatus;          /* PS�����״̬*/
    VOS_UINT32  ulCsCause;                  /* CS��ԭ��ֵ */
    VOS_UINT32  ulPsCause;                  /* PS��ԭ��ֵ */
    VOS_UINT8   ucDomainFlag;               /* ����Ч�ı�־λ*/
} STA_PHONE_DATA_S;


/*------------  ����״̬�ϱ���Ӧ���� ----------*/
VOS_UINT32 Sta_ServiceStatusInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

/*-------------  DETACH������Ӧ���� -----------*/

/*-------------  DETACH�ϱ���Ӧ���� -----------*/
VOS_UINT32 Sta_DetachInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

/*------------  PLMN����������Ӧ���� ----------*/
VOS_UINT32 Sta_PlmnListInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_VOID TAF_MMA_PlmnListErrorReport(
    TAF_ERROR_CODE_ENUM_UINT32          enError
);
VOS_VOID TAF_MMA_PlmnListQryAbortReport(VOS_VOID);

/*-----------  CoverageAreaInd��Ӧ���� --------*/
VOS_UINT32 Sta_CoverageAreaInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

/*----------- PLMN�����ܾ�������Ӧ���� --------*/
VOS_UINT32 Sta_PlmnListRej(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_UINT32 Sta_DataTranAttri(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);


VOS_VOID MN_PH_UpdateBeginRegTime( VOS_VOID  );

/* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */


#if 0
VOS_UINT32   Sta_SyncMsClassType(VOS_UINT32 opId,
                                 TAF_PH_MS_CLASS_TYPE ucMsClass);
#endif

VOS_VOID Sta_UpdateDataTranStatusAndMode(NAS_MSCC_PIF_DATATRAN_ATTRI_ENUM_UINT8 enDataTranAttri);

/* Deleted by s00217060 for VoLTE_PhaseII  ��Ŀ, 2013-11-04, begin */
/* VOS_VOID Sta_DataTranAttri(MSCC_MMA_DATATRAN_ATTRI_IND_STRU *pstDataTranAttri); */
/* Deleted by s00217060 for VoLTE_PhaseII  ��Ŀ, 2013-11-04, end */
VOS_VOID Sta_ModeChangeEventReport(VOS_UINT8 ucNewSysMode, VOS_UINT8 ucNewSysSubMode);

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*---------- ��Э��ջ����������Ϣ��������(�ڲ�)----------*/
/*=======================================================*/
/*------------- Э��ջ������Ϣ�ӿ�-------------*/
/*------------- Э��ջ������ֹ�ӿ�-------------*/
#define STA_MSGABORT_OK                 0    /* ���������¼� */
#define STA_MSGABORT_ERR                1    /* ���ش����¼� */
VOS_UINT32 Sta_MsgReqAbort ( VOS_UINT32 ulAbortType );

/*=======================================================*/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*--------------- STATUS�ڲ����ݴ�������  ---------------*/
/*=======================================================*/

VOS_VOID Sta_ReOrderPlmnList (TAF_PLMN_LIST_STRU* pPlmnList);
VOS_UINT32 Sta_UpdateData ( STA_PHONE_DATA_S *pData );

VOS_VOID   Sta_EventReport ( VOS_UINT32 ulOpId, VOS_UINT32 ulEventType );

VOS_UINT32 Sta_UpdateFsmFlag ( VOS_UINT8 ucFsmSub,
                    VOS_UINT32 ulFsm, VOS_UINT32 ulType );

VOS_UINT8 Sta_FindFsmSubBySubSta ( VOS_UINT8 ucFsmSubSta );
VOS_UINT32 Sta_IsDualFsmSub ( VOS_VOID );


VOS_UINT32 Sta_FindIdelFsmSub ( VOS_UINT8 ucSubState );

VOS_BOOL Sta_IsFsmSubValid ( VOS_UINT8 ucFsmSub, VOS_UINT32 ulFsm );

VOS_BOOL Sta_IsInvalidOpId ( VOS_UINT32 ulOpId );

VOS_VOID Sta_ClearCurPlmnId(TAF_PLMN_ID_STRU *pstNewPlmnId);
VOS_VOID Sta_InitCurPlmnId(TAF_PLMN_ID_STRU    stSrcPlmnId,
                             TAF_PLMN_ID_STRU   *pstDstPlmnId);

VOS_VOID Sta_DetachTimeoutProc4App(STA_TIMER_NAME_E    TimerId,
                                   VOS_UINT16          TimerIndex,
                                   VOS_UINT8           ucOperate);

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */
#if 0
VOS_UINT32 Sta_ProcSetMsClassTypeforDetach(MSCC_MMA_DETACH_CNF_STRU *pDetachCnf );


VOS_UINT32 Sta_SuccessDetach(MSCC_MMA_DETACH_CNF_STRU *pDetachCnf );


VOS_UINT32 Sta_CompleteDefMsClassType(MSCC_MMA_DETACH_CNF_STRU *pDetachCnf );



/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */

VOS_VOID Sta_ProcMsClassTypeNewToOld(TAF_PH_MS_CLASS_TYPE   CurMsClassType,
                                       TAF_PH_MS_CLASS_TYPE   NewMsClassType,
                                       VOS_UINT32            *pulAttachType,
                                       VOS_UINT32            *pulDetachType);


#endif

extern VOS_UINT32 Sta_StopAllRunningTimer(VOS_VOID);
/* Deleted by s00217060 for VoLTE_PhaseII  ��Ŀ, 2013-11-04, begin */
/* extern VOS_VOID Sta_ResetFsmFlg(VOS_VOID); */
/* Deleted by s00217060 for VoLTE_PhaseII  ��Ŀ, 2013-11-04, end */
#if 0
VOS_VOID Sta_AttachByModeService(VOS_UINT32  ulOpId);
#endif
/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, begin */

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, end */
/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */

VOS_VOID Sta_GetLocInfoForSat(MMA_MSCC_PLMN_ID_STRU stPlmnId, VOS_UINT16 usLac, VOS_UINT16 usCellId,
                              VOS_UINT8 *pucLocInfo);
/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

VOS_UINT8 Sta_GetStatusForSat(VOS_UINT32 ulServiceStatus);
/* Deleted by s00217060 for VoLTE_PhaseII  ��Ŀ, 2013-11-04, begin */
/* VOS_UINT32 Sta_SysCfgCnf( MSCC_MMA_SYS_CFG_SET_CNF_STRU  *pstSysCfgCnf); */
/* Deleted by s00217060 for VoLTE_PhaseII  ��Ŀ, 2013-11-04, end */
/* ����״̬�ϱ���ͳһ�ŵ�Sta_ServiceStatusInd()����,attach cnf �� detach cnf���������� */

VOS_VOID Mma_ComGetServiceStatusForReport(VOS_UINT32 ulCsServiceStatus,
                                       VOS_UINT32 ulPsServiceStatus,
                                       VOS_UINT32 ulCsCause,
                                       VOS_UINT32 ulPsCause);
VOS_VOID Sta_UpdateServiceStatus(VOS_UINT32 ulServiceStatus,
                             VOS_UINT32 ulCnDomain);

/* Added by l00208543 for V9R1 STK����, 2013-07-26, begin */
TAF_SDC_REPORT_SRVSTA_ENUM_UINT8 TAF_MMA_GetSrvTypeForStk(VOS_VOID);

VOS_VOID TAF_MMA_ProcLociStatusEvent(VOS_VOID);


TAF_SDC_SERVICE_STATUS_ENUM_UINT8 TAF_MMA_ConvertSrvTypeForStk(
                                    TAF_SDC_SERVICE_STATUS_ENUM_UINT8  enTafSrvType
                                    );


VOS_VOID TAF_MMA_ProcCsServiceStatusChanged(VOS_UINT8 ucOldCsServiceStatus);

VOS_UINT8 TAF_MMA_IsCsServiceStatusChanged(VOS_UINT8 ucOldCsServiceStatus);

VOS_UINT8 TAF_MMA_IsPsServiceStatusChanged(VOS_UINT8 ucOldPsServiceStatus);

TAF_SDC_REPORT_SRVSTA_ENUM_UINT8 TAF_MMA_ConvertTafSrvStaToStkType(
                            TAF_SDC_REPORT_SRVSTA_ENUM_UINT8      enTafSrvType
                            );

/* Added by l00208543 for V9R1 STK����, 2013-07-26, end */

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
VOS_VOID Mma_ModeChgReport(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enCurNetWork,
    VOS_UINT8                           ucSysSubMode
);


/* Deleted by z00161729 for V9R1 STK����, 2013-7-24, begin */
/* Deleted by z00161729 for V9R1 STK����, 2013-7-24, end */

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

/* Added by l00208543 for V9R1 STK����, 2013-07-22, begin */
TAF_MMA_RAT_TYPE_ENUM_UINT8 TAF_MMA_ConvertMmaRatToStkRat(
                                         TAF_SDC_SYS_MODE_ENUM_UINT8 enMmaRatType
                                         );
/* Added by l00208543 for V9R1 STK����, 2013-07-22, end */

TAF_PH_PLMN_SELECTION_RESULT_ENUM_UINT32 TAF_MMA_ConvertServiceTypeToAtType(
    NAS_MSCC_PIF_PLMN_SELECTION_RESULT_ENUM_UINT32 enMmaServiceType
);




/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */
/* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
extern VOS_UINT32 Sta_MmInfo(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);




/* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */


/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */


extern  VOS_UINT8 Sta_GetSysSubMode_W(STA_DATA_TRANSFER_STATUS_UINT8      ucDataTranStatus ,
                                       STA_DATA_TRANSFER_MODE_UINT8        ucDataTranMode
                                       );


VOS_UINT8 Sta_GetSysSubMode_Td(
    STA_DATA_TRANSFER_STATUS_UINT8      ucDataTranStatus,
    STA_DATA_TRANSFER_MODE_UINT8        ucDataTranMode
);

extern VOS_VOID NAS_MSCC_GetCsPsSimStatus(
    VOS_BOOL                           *pbCsSimStatus,
    VOS_BOOL                           *pbPsSimStatus);

extern VOS_VOID NAS_MN_ReportPlmnSrchResult(
    VOS_UINT32                  ulResult
);
extern VOS_VOID TAF_MMA_ReportSpecPlmnSrchResult(
    VOS_UINT32                  ulResult
);
extern VOS_VOID TAF_MMA_ReportAutoPlmnSrchResult(
    VOS_UINT32                  ulResult
);
extern VOS_UINT32  MN_PH_GetRegCostTime( VOS_VOID );

TAF_PH_MODE MMA_GetCurrPhMode(VOS_VOID);

VOS_VOID TAF_MMA_ReportPlmnModeEvent(VOS_UINT8 ucPlmnMode);
VOS_UINT32 TAF_MMA_IsEnablePlmnList(VOS_VOID);
VOS_UINT32 TAF_MMA_IsEnableDeAttach(VOS_VOID);
VOS_VOID TAF_MMA_SndAutoPlmnReselect_Refresh(VOS_VOID);

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */
/* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
/* VOS_UINT32 TAF_MMA_RcvMsccPlmnReselCnf(MSCC_MMA_PLMN_RESEL_CNF_STRU *pstMsg); */
VOS_UINT32 TAF_MMA_RcvMsccPlmnSpecialSelCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_UINT32 TAF_MMA_RcvMsccPlmnReselCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

/* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

VOS_VOID TAF_MMA_ProcPhoneStop_NotEnableStatus(VOS_VOID);
VOS_UINT32 TAF_MMA_IsEnablePlmnSelect(VOS_VOID);

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, begin */
VOS_VOID TAF_MMA_DeleteRatType(
    TAF_MMA_RAT_TYPE_ENUM_UINT8          ucRatType,
    TAF_MMA_RAT_ORDER_STRU              *pstPlmnRatPrioList
);
/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, end */

VOS_VOID TAF_MMA_GetAvailablePlmnRatPrio(TAF_MMA_RAT_ORDER_STRU *pstRatPrioList);



/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
VOS_UINT8 TAF_MMA_IsModeChange(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enCurNetWork,
    VOS_UINT8                           ucSysSubMode
);

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */



VOS_VOID TAF_MMA_PlmnListAbortCnfUserAbort (MSCC_MMA_PLMN_LIST_ABORT_CNF_STRU *pPlmnListAbortCnf);
/* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
VOS_UINT32 TAF_MMA_RcvPlmnListAbortCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_UINT32 TAF_MMA_RcvSpecPlmnSearchAbortCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_UINT32 TAF_MMA_RcvMsccUserPlmnRej(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

/* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
VOS_VOID  TAF_MMA_RcvTimerPlmnListCnfExpired(VOS_UINT32 ulOpId);

VOS_VOID  TAF_MMA_RcvUserAbortPlmnList(
    VOS_UINT16                          usClientId,
    VOS_UINT32                          ulOpId
);

VOS_VOID TAF_MMA_PlmnListReport(
    TAF_MMA_PLMN_LIST_CNF_PARA_STRU    *pstPlmnListCnfPara
);
VOS_VOID TAF_MMA_PlmnListClearOperCtx(VOS_VOID);
VOS_VOID TAF_MMA_PlmnListQryAbortReport();
VOS_VOID Sta_PlmnListEventReport(VOS_VOID);

#if (FEATURE_ON == FEATURE_CSG)
VOS_VOID TAF_MMA_ReportCsgListError(
    TAF_MMA_CTRL_STRU                  *pstCtrl,
    TAF_ERROR_CODE_ENUM_UINT32          enError
);
VOS_VOID TAF_MMA_ClearCsgListSearchOperCtx(VOS_VOID);

VOS_VOID TAF_MMA_ReportCsgListSearchResult(
    TAF_MMA_CTRL_STRU                  *pstCtrl,
    TAF_MMA_PLMN_LIST_CTRL_STRU        *pstPlmnListCtrl
);


#endif



/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */


VOS_UINT32 TAF_MMA_IsGsmAccessForbidden(VOS_VOID);
/* Deleted by s00217060 for VoLTE_PhaseI  ��Ŀ, 2013-07-22, begin */
/* Deleted by s00217060 for VoLTE_PhaseI  ��Ŀ, 2013-07-22, end */

VOS_UINT32 TAF_MMA_IsExistPlmnRatAllowAccess(VOS_VOID);

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
VOS_VOID TAF_MMA_ReportRegStatus(
    NAS_MSCC_PIF_REG_STATE_ENUM_UINT8        enRegState,
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32        enCnDomainId
);
/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */

VOS_UINT32 TAF_MMA_IsCsServDomainAvail(
    TAF_PH_MS_CLASS_TYPE                enMsClassType
);



VOS_VOID TAF_MMA_SndStkCsServiceChangeNotify(
    TAF_CS_SERVICE_ENUM_UINT32          enCsState
);

/* Deleted by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-10, begin */

/* Deleted by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-10, end */


VOS_UINT32 TAF_MMA_IsNeedSndStkEvt(VOS_VOID);

VOS_VOID TAF_MMA_SndMtaAreaLostInd(VOS_VOID);

/* Added by w00176964 for VoLTE_PhaseIII ��Ŀ, 2013-12-19, begin */
VOS_UINT32  TAF_MMA_PlmnReselectAutoReq_PowerOff(VOS_UINT32 ulOpID);
VOS_UINT32  TAF_MMA_RcvPlmnSelectionReq_PowerOff(
    TAF_MMA_PLMN_SPECIAL_SEL_REQ_STRU  *pstPlmnUserSelMsg,
    TAF_PLMN_ID_STRU                    stPlmnId,
    TAF_PH_RA_MODE                      ucAccessMode,
    VOS_UINT8                           ucReselMode
);

/* Added by w00176964 for VoLTE_PhaseIII ��Ŀ, 2013-12-19, end */

VOS_UINT32 TAF_MMA_IsPsServDomainAvail(
    TAF_PH_MS_CLASS_TYPE                enMsClassType
);



extern VOS_UINT32  TAF_MMA_RcvPlmnListAbortReq_Main(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_UINT32 TAF_MMA_IsNeedReportRegStatus_ServiceStatusInd(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enOldAppSysMode,
    TAF_SDC_SYS_SUBMODE_ENUM_UINT8      enOldAppSysSubMode,
    TAF_SDC_SERVICED_PLMN_INFO_STRU    *pstOldPlmnInfo
);
VOS_UINT32 TAF_MMA_IsNeedReportRegStatus_RegStatusInd(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32  enCnDomainId,
    TAF_SDC_REG_STATUS_ENUM_UINT8       enOldCsRegState,
    TAF_SDC_REG_STATUS_ENUM_UINT8       enOldPsRegState,
    TAF_SDC_REG_STATUS_ENUM_UINT8       enRegState
);
#if (FEATURE_ON == FEATURE_BASTET)
VOS_VOID TAF_MMA_ProcBastetServiceStatusInd(
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enOldCsSrvSta,
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enOldPsSrvSta
);
#endif

#if (FEATURE_ON == FEATURE_PTM)
VOS_UINT32 TAF_MMA_CheckRatValid(VOS_UINT8 ucSysMode);
VOS_VOID TAF_MMA_RatFrequentlySwitchProc(
    NAS_ERR_LOG_RAT_SWITCH_RECORD_STRU  *pstNewRatSwitchRecord
);
VOS_VOID TAF_MMA_RatSwitchRecord(
    TAF_PH_INFO_RAT_TYPE               ucNewSysMode
);
#endif



VOS_VOID TAF_MMA_ProcAppServPlmnInfo_SysInfoInd(
    MSCC_MMA_3GPP_SYS_INFO_IND_STRU    *pstSysInfoInd
);
VOS_VOID TAF_MMA_ProcServiceStatusReport_ServiceStatusInd(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
);
VOS_VOID TAF_MMA_ProcRegStatusReport_ServiceStatusInd(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enOldAppSysMode,
    TAF_SDC_SYS_SUBMODE_ENUM_UINT8      enOldAppSysSubMode,
    TAF_SDC_SERVICED_PLMN_INFO_STRU    *pstOldPlmnInfo
);

VOS_VOID TAF_MMA_ProcRssiReport_ServiceStatusInd(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enOldSysMode
);


VOS_UINT32 TAF_MMA_IsNeedDelayReportRegStatus(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32  enCnDomainId,
    NAS_MSCC_PIF_REG_STATE_ENUM_UINT8   enNewRegState
);

VOS_UINT32 TAF_MMA_IsNeedDelayReportApsNoServiceStatus(
    TAF_MMA_DELAY_CL_REPORT_TYPE_ENUM_UINT8                 enDelayType
);

VOS_UINT32 TAF_MMA_IsNeedReportServiceStatus(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32        enCnDomainId,
    NAS_MSCC_PIF_SERVICE_STATUS_ENUM_UINT32   enServiceStatus
);

VOS_UINT32 TAF_MMA_IsNeedDelayReportServiceStatus(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32        enCnDomainId,
    NAS_MSCC_PIF_SERVICE_STATUS_ENUM_UINT32   enServiceStatus
);

VOS_UINT32 TAF_MMA_IsNeedReportServiceStatus_DelayRptTimerRun(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32       enCnDomainId
);

VOS_UINT32 TAF_MMA_IsNeedReportRegState_DelayRptTimerRun(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32  enCnDomainId,
    TAF_SDC_REG_STATUS_ENUM_UINT8       enRegState
);

VOS_UINT8 TAF_SDC_IsSpecDomainUsimStatusInvalid(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32        enCnDomainId
);

extern VOS_UINT32 TAF_SDC_IsUsimStausValid(VOS_VOID);

VOS_VOID TAF_MMA_NotifySrvInfoToSpm(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32       enCnDomainId,
    NAS_MSCC_PIF_SERVICE_STATUS_ENUM_UINT32  enServiceStatus,
    NAS_MSCC_PIF_SERVICE_STATUS_ENUM_UINT32  enOldPsServiceStatus
);

VOS_UINT32 TAF_MMA_RcvDelayReportServiceStatusExpired_PreProc(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_UINT32 TAF_MMA_RcvDelayReportCLNoServiceExpired_PreProc(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_UINT32 TAF_MMA_RcvDelayReportDONoServiceExpired_PreProc(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);

VOS_VOID Sta_ReportServiceEvent(
    VOS_UINT32                          ulCsServiceStatus,
    VOS_UINT32                          ulPsServiceStatus
);
VOS_VOID TAF_MMA_ProcServiceStatusReport(
    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8 ucNewSrvSta,
    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8 ucOldSrvSta
);
VOS_VOID TAF_MMA_Proc3gppMsccServiceStatusInd(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
);

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

VOS_VOID TAF_MMA_Proc3gppMsccRegStatusIndClMode(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
);

VOS_VOID TAF_MMA_Update3GppServiceStatusAndDomainCLMode(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
);

VOS_VOID TAF_MMA_UpdateSrvRegSta_Main(
    TAF_SDC_SRV_REG_INFO_STRU          *pstSrvInfo,
    TAF_PH_ACCESS_TECH_ENUM_UINT8       enAct
);

#endif

VOS_VOID TAF_MMA_Proc3gppMsccRegStatusIndGulMode(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
);

VOS_VOID TAF_MMA_Proc3gppMsccRegStatusInd(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
);

/*=======================================================*/

/*=================================================================*/
#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif
#ifdef __cplusplus
}
#endif
/*****************************************************************************/

/*===========================================================================*/
#endif      /* __STATUS_H__*/

/***** End of the file *****/