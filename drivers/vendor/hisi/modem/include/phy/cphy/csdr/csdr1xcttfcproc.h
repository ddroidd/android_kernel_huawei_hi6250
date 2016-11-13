/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2011

 ********************************************************************************
 * @author
 * @version
 * @date      2014-09-22
 * @file
 * @brief
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef CSDR1XCTTFCPROC_H
#define CSDR1XCTTFCPROC_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/
#include "uphy_type_define.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/

/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/
/** ****************************************************************************
 * Name        : CSDR_1X_CODE_TYPE_ENUM_UINT16
 *
 * Description : This is an ENUM for conveying the code type.
 *******************************************************************************/
enum CSDR_1X_CODE_TYPE_ENUM
{
    CSDR_1X_CODE_TYPE_CONVOLUTIONAL     = 0x0000,
    CSDR_1X_CODE_TYPE_TURBO             = 0x0001,
    CSDR_1X_CODE_TYPE_ENUM_BUTT         = 0x0002
};
typedef unsigned short CSDR_1X_CODE_TYPE_ENUM_UINT16;



/*******************************************************************************
 7. OTHER declarations
*******************************************************************************/

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif