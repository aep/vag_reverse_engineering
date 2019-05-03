#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Serial.c Config.c main.c plib/USART/u1baud.c plib/USART/u1busy.c plib/USART/u1close.c plib/USART/u1defs.c plib/USART/u1drdy.c plib/USART/u1gets.c plib/USART/u1open.c plib/USART/u1putrs.c plib/USART/u1puts.c plib/USART/u1read.c plib/USART/u1write.c can/ECANPoll.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Serial.p1 ${OBJECTDIR}/Config.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/plib/USART/u1baud.p1 ${OBJECTDIR}/plib/USART/u1busy.p1 ${OBJECTDIR}/plib/USART/u1close.p1 ${OBJECTDIR}/plib/USART/u1defs.p1 ${OBJECTDIR}/plib/USART/u1drdy.p1 ${OBJECTDIR}/plib/USART/u1gets.p1 ${OBJECTDIR}/plib/USART/u1open.p1 ${OBJECTDIR}/plib/USART/u1putrs.p1 ${OBJECTDIR}/plib/USART/u1puts.p1 ${OBJECTDIR}/plib/USART/u1read.p1 ${OBJECTDIR}/plib/USART/u1write.p1 ${OBJECTDIR}/can/ECANPoll.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/Serial.p1.d ${OBJECTDIR}/Config.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/plib/USART/u1baud.p1.d ${OBJECTDIR}/plib/USART/u1busy.p1.d ${OBJECTDIR}/plib/USART/u1close.p1.d ${OBJECTDIR}/plib/USART/u1defs.p1.d ${OBJECTDIR}/plib/USART/u1drdy.p1.d ${OBJECTDIR}/plib/USART/u1gets.p1.d ${OBJECTDIR}/plib/USART/u1open.p1.d ${OBJECTDIR}/plib/USART/u1putrs.p1.d ${OBJECTDIR}/plib/USART/u1puts.p1.d ${OBJECTDIR}/plib/USART/u1read.p1.d ${OBJECTDIR}/plib/USART/u1write.p1.d ${OBJECTDIR}/can/ECANPoll.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Serial.p1 ${OBJECTDIR}/Config.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/plib/USART/u1baud.p1 ${OBJECTDIR}/plib/USART/u1busy.p1 ${OBJECTDIR}/plib/USART/u1close.p1 ${OBJECTDIR}/plib/USART/u1defs.p1 ${OBJECTDIR}/plib/USART/u1drdy.p1 ${OBJECTDIR}/plib/USART/u1gets.p1 ${OBJECTDIR}/plib/USART/u1open.p1 ${OBJECTDIR}/plib/USART/u1putrs.p1 ${OBJECTDIR}/plib/USART/u1puts.p1 ${OBJECTDIR}/plib/USART/u1read.p1 ${OBJECTDIR}/plib/USART/u1write.p1 ${OBJECTDIR}/can/ECANPoll.p1

# Source Files
SOURCEFILES=Serial.c Config.c main.c plib/USART/u1baud.c plib/USART/u1busy.c plib/USART/u1close.c plib/USART/u1defs.c plib/USART/u1drdy.c plib/USART/u1gets.c plib/USART/u1open.c plib/USART/u1putrs.c plib/USART/u1puts.c plib/USART/u1read.c plib/USART/u1write.c can/ECANPoll.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F25K80
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Serial.p1: Serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Serial.p1.d 
	@${RM} ${OBJECTDIR}/Serial.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Serial.p1 Serial.c 
	@-${MV} ${OBJECTDIR}/Serial.d ${OBJECTDIR}/Serial.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Serial.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Config.p1: Config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Config.p1.d 
	@${RM} ${OBJECTDIR}/Config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Config.p1 Config.c 
	@-${MV} ${OBJECTDIR}/Config.d ${OBJECTDIR}/Config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1baud.p1: plib/USART/u1baud.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1baud.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1baud.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1baud.p1 plib/USART/u1baud.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1baud.d ${OBJECTDIR}/plib/USART/u1baud.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1baud.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1busy.p1: plib/USART/u1busy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1busy.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1busy.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1busy.p1 plib/USART/u1busy.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1busy.d ${OBJECTDIR}/plib/USART/u1busy.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1busy.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1close.p1: plib/USART/u1close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1close.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1close.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1close.p1 plib/USART/u1close.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1close.d ${OBJECTDIR}/plib/USART/u1close.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1close.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1defs.p1: plib/USART/u1defs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1defs.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1defs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1defs.p1 plib/USART/u1defs.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1defs.d ${OBJECTDIR}/plib/USART/u1defs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1defs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1drdy.p1: plib/USART/u1drdy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1drdy.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1drdy.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1drdy.p1 plib/USART/u1drdy.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1drdy.d ${OBJECTDIR}/plib/USART/u1drdy.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1drdy.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1gets.p1: plib/USART/u1gets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1gets.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1gets.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1gets.p1 plib/USART/u1gets.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1gets.d ${OBJECTDIR}/plib/USART/u1gets.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1gets.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1open.p1: plib/USART/u1open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1open.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1open.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1open.p1 plib/USART/u1open.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1open.d ${OBJECTDIR}/plib/USART/u1open.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1open.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1putrs.p1: plib/USART/u1putrs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1putrs.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1putrs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1putrs.p1 plib/USART/u1putrs.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1putrs.d ${OBJECTDIR}/plib/USART/u1putrs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1putrs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1puts.p1: plib/USART/u1puts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1puts.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1puts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1puts.p1 plib/USART/u1puts.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1puts.d ${OBJECTDIR}/plib/USART/u1puts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1puts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1read.p1: plib/USART/u1read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1read.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1read.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1read.p1 plib/USART/u1read.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1read.d ${OBJECTDIR}/plib/USART/u1read.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1read.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1write.p1: plib/USART/u1write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1write.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1write.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1write.p1 plib/USART/u1write.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1write.d ${OBJECTDIR}/plib/USART/u1write.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1write.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/can/ECANPoll.p1: can/ECANPoll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/can" 
	@${RM} ${OBJECTDIR}/can/ECANPoll.p1.d 
	@${RM} ${OBJECTDIR}/can/ECANPoll.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/can/ECANPoll.p1 can/ECANPoll.c 
	@-${MV} ${OBJECTDIR}/can/ECANPoll.d ${OBJECTDIR}/can/ECANPoll.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/can/ECANPoll.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/Serial.p1: Serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Serial.p1.d 
	@${RM} ${OBJECTDIR}/Serial.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Serial.p1 Serial.c 
	@-${MV} ${OBJECTDIR}/Serial.d ${OBJECTDIR}/Serial.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Serial.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Config.p1: Config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Config.p1.d 
	@${RM} ${OBJECTDIR}/Config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Config.p1 Config.c 
	@-${MV} ${OBJECTDIR}/Config.d ${OBJECTDIR}/Config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1baud.p1: plib/USART/u1baud.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1baud.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1baud.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1baud.p1 plib/USART/u1baud.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1baud.d ${OBJECTDIR}/plib/USART/u1baud.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1baud.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1busy.p1: plib/USART/u1busy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1busy.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1busy.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1busy.p1 plib/USART/u1busy.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1busy.d ${OBJECTDIR}/plib/USART/u1busy.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1busy.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1close.p1: plib/USART/u1close.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1close.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1close.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1close.p1 plib/USART/u1close.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1close.d ${OBJECTDIR}/plib/USART/u1close.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1close.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1defs.p1: plib/USART/u1defs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1defs.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1defs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1defs.p1 plib/USART/u1defs.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1defs.d ${OBJECTDIR}/plib/USART/u1defs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1defs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1drdy.p1: plib/USART/u1drdy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1drdy.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1drdy.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1drdy.p1 plib/USART/u1drdy.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1drdy.d ${OBJECTDIR}/plib/USART/u1drdy.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1drdy.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1gets.p1: plib/USART/u1gets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1gets.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1gets.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1gets.p1 plib/USART/u1gets.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1gets.d ${OBJECTDIR}/plib/USART/u1gets.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1gets.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1open.p1: plib/USART/u1open.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1open.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1open.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1open.p1 plib/USART/u1open.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1open.d ${OBJECTDIR}/plib/USART/u1open.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1open.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1putrs.p1: plib/USART/u1putrs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1putrs.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1putrs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1putrs.p1 plib/USART/u1putrs.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1putrs.d ${OBJECTDIR}/plib/USART/u1putrs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1putrs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1puts.p1: plib/USART/u1puts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1puts.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1puts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1puts.p1 plib/USART/u1puts.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1puts.d ${OBJECTDIR}/plib/USART/u1puts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1puts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1read.p1: plib/USART/u1read.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1read.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1read.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1read.p1 plib/USART/u1read.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1read.d ${OBJECTDIR}/plib/USART/u1read.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1read.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/plib/USART/u1write.p1: plib/USART/u1write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/plib/USART" 
	@${RM} ${OBJECTDIR}/plib/USART/u1write.p1.d 
	@${RM} ${OBJECTDIR}/plib/USART/u1write.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/plib/USART/u1write.p1 plib/USART/u1write.c 
	@-${MV} ${OBJECTDIR}/plib/USART/u1write.d ${OBJECTDIR}/plib/USART/u1write.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/plib/USART/u1write.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/can/ECANPoll.p1: can/ECANPoll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/can" 
	@${RM} ${OBJECTDIR}/can/ECANPoll.p1.d 
	@${RM} ${OBJECTDIR}/can/ECANPoll.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/can/ECANPoll.p1 can/ECANPoll.c 
	@-${MV} ${OBJECTDIR}/can/ECANPoll.d ${OBJECTDIR}/can/ECANPoll.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/can/ECANPoll.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -fasmfile -maddrqual=request -xassembler-with-cpp -I"../../../../opt/microchip/xc8/v2.05/include/plib" -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/elm327.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
