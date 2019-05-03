
#include<p18cxxx.h>         // You may need to modify this processor file

/*******************************************************************/
/*                                                                 */
/*  NOTE:  The user MUST modify this file to specified the         */
/*         desired PIC18Cxxx I/O pin that will be used to          */
/*         interface to the MCP2510 CS pin                         */
/*                                                                 */
/*         IF THIS FILE IS MODIFIED, THE FILE CANENABL.C MUST      */
/*         BE RECOMPILED!                                          */
/*                                                                 */
/*******************************************************************/

#define   Port   C       //  PORT used     PORTC (use A, B, C, D, ...)
#define   Pin    2       //  Pin used      RC2



/*******************************************************************/
/*******************************************************************/
/*    DO NOT MODIFY FILE PAST HERE                                 */
/*                                                                 */
/*******************************************************************/
/*******************************************************************/

//
//  This is to help with the automatic substitutions
//
#define   LATname(x)    LAT##x
#define   TRISname(x)   TRIS##x


