/**
 *  Common header for Qt binding definition library
 *
 *  DO NOT EDIT THIS FILE. 
 *  This file has been created automatically
 */

#include "tlDefs.h"

#define FORCE_LINK_GSI_QTSQL static void force_link_gsiQtSql_f () { extern int force_link_gsiQtSql; force_link_gsiQtSql = 0; }

#if !defined(HDR_gsiQtSqlCommon_h)
# define HDR_gsiQtSqlCommon_h

# ifdef MAKE_GSI_QTSQL_LIBRARY
#   define GSI_QTSQL_PUBLIC           DEF_INSIDE_PUBLIC
#   define GSI_QTSQL_PUBLIC_TEMPLATE  DEF_INSIDE_PUBLIC_TEMPLATE
#   define GSI_QTSQL_LOCAL            DEF_INSIDE_LOCAL
# else
#   define GSI_QTSQL_PUBLIC           DEF_OUTSIDE_PUBLIC
#   define GSI_QTSQL_PUBLIC_TEMPLATE  DEF_OUTSIDE_PUBLIC_TEMPLATE
#   define GSI_QTSQL_LOCAL            DEF_OUTSIDE_LOCAL
# endif

#endif
