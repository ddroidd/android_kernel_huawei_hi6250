/******************************************************************************

                  ��Ȩ���� (C), 2014, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : BST_DSPP_Report.cpp
  �� �� ��   : ����
  ��    ��   : d00173029
  ��������   : 2014��4��16��
  ����޸�   :
  ��������   : DSPP Э����Slave���������ϱ��Ľӿ�
  �����б�   :

  �޸���ʷ   :
1.��    ��   : 2014��04��16��
  ��    ��   : d00173029
  �޸�����   : �����ļ�

******************************************************************************/

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "BST_DSPP_Report.h"
#include "BST_DSPP_AppLayer.h"
#include "BST_DBG_MemLeak.h"
/*lint -e767*/
#define    THIS_FILE_ID        PS_FILE_ID_BST_DSPP_REPORT_CPP
/*lint +e767*/
/*****************************************************************************
  2 ����ʵ��
******************************************************************************/

/*****************************************************************************
�� �� ��  : BST_DSPP_CReport
��������  : ��BST_DSPP_CReport�Ĺ��캯��
�������  : BST_PROCID_T usProcId
            BST_TASKID_T usTaskId
�������  : ��
�� �� ֵ  : ��
���ú���  :
��������  :

�޸���ʷ  :
1.��   �� : 2014��04��16��
  ��   �� : d00173029
  �޸�����: �����ļ�
*****************************************************************************/
BST_DSPP_CReport::BST_DSPP_CReport ( BST_PROCID_T usProcId,
                                     BST_TASKID_T usTaskId )
{
    usHostProcId                        = usProcId;
    usHostTaskId                        = usTaskId;
}

/*****************************************************************************
�� �� ��  : Report
��������  : ���ͱ���
�������  : BST_ERR_ENUM_UINT8 enErrMsg
�������  :
�� �� ֵ  : BST_ERR_ENUM_UINT8
���ú���  :
��������  :

�޸���ʷ  :
1.��   �� : 2014��04��16��
  ��   �� : d00173029
  �޸�����: �����ļ�
*****************************************************************************/
BST_ERR_ENUM_UINT8  BST_DSPP_CReport::Report ( BST_ERR_ENUM_UINT8 enErrMsg )
{
    BST_DSPP_CAppUlVa                  *pcDsppApUlVa;

    pcDsppApUlVa                       = BST_DSPP_CAppUlVa::GetInstance ();
    if ( BST_NULL_PTR == pcDsppApUlVa )
    {
        return BST_ERR_INVALID_PTR;
    }
    return ( pcDsppApUlVa->Report ( usHostProcId, usHostTaskId, enErrMsg ) );
}
/*****************************************************************************
�� �� ��  : Report
��������  : ���ͱ���
�������  : BST_CORE_PID_ENUM_UINT16  enParamId
            BST_UINT16                usCmdLen
            BST_VOID                 *pRptParam
�������  :
�� �� ֵ  : BST_ERR_ENUM_UINT8
���ú���  :
��������  :

�޸���ʷ  :
1.��   �� : 2014��04��16��
  ��   �� : d00173029
  �޸�����: �����ļ�
*****************************************************************************/
BST_ERR_ENUM_UINT8  BST_DSPP_CReport::Report ( BST_CORE_PID_ENUM_UINT16  enParamId,
                                               BST_UINT16                usCmdLen,
                                               BST_VOID                 *pRptParam )
{
    BST_DSPP_CAppUlVa                  *pcDsppApUlVa;

    pcDsppApUlVa                       = BST_DSPP_CAppUlVa::GetInstance ();
    if ( BST_NULL_PTR == pcDsppApUlVa )
    {
        return BST_ERR_INVALID_PTR;
    }
    return ( pcDsppApUlVa->Report ( usHostProcId, usHostTaskId,
                                  usCmdLen, enParamId, (BST_UINT8 *)pRptParam ) );
}
