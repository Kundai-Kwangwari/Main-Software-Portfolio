#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/9f144e6/AddressAllocation.o \
	${OBJECTDIR}/_ext/9f144e6/Date.o \
	${OBJECTDIR}/_ext/9f144e6/InlineSearch.o \
	${OBJECTDIR}/_ext/9f144e6/RetrieveDataAddress.o \
	${OBJECTDIR}/_ext/9f144e6/main.o \
	${OBJECTDIR}/_ext/9f144e6/md5.o \
	${OBJECTDIR}/_ext/9f144e6/stringh.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/zimhealth.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/zimhealth.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/zimhealth ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/9f144e6/AddressAllocation.o: ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/AddressAllocation.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9f144e6
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9f144e6/AddressAllocation.o ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/AddressAllocation.c

${OBJECTDIR}/_ext/9f144e6/Date.o: ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/Date.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9f144e6
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9f144e6/Date.o ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/Date.c

${OBJECTDIR}/_ext/9f144e6/InlineSearch.o: ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/InlineSearch.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9f144e6
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9f144e6/InlineSearch.o ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/InlineSearch.c

${OBJECTDIR}/_ext/9f144e6/RetrieveDataAddress.o: ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/RetrieveDataAddress.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9f144e6
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9f144e6/RetrieveDataAddress.o ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/RetrieveDataAddress.c

${OBJECTDIR}/_ext/9f144e6/main.o: ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9f144e6
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9f144e6/main.o ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/main.c

${OBJECTDIR}/_ext/9f144e6/md5.o: ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/md5.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9f144e6
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9f144e6/md5.o ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/md5.c

${OBJECTDIR}/_ext/9f144e6/stringh.o: ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/stringh.c
	${MKDIR} -p ${OBJECTDIR}/_ext/9f144e6
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9f144e6/stringh.o ../../../Downloads/ZIMHEALTH2-20211226T084009Z-001/ZIMHEALTH2/stringh.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
