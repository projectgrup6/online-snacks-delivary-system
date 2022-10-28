SRCDIR = ../src
OBJDIR = ../obj
BINDIR = ../bin
INCDIR = ../include
CFLAGS = gcc -c -g -I${INCDIR}
all: main.o options.o admin.o menu_admin.o menu_user.o clear.o
main.o:
	${CFLAGS} ${SRCDIR}/main.c -o ${OBJDIR}/main.o
options.o:
	${CFLAGS} ${SRCDIR}/options.c -o ${OBJDIR}/options.o
admin.o:
	${CFLAGS} ${SRCDIR}/admin.c -o ${OBJDIR}/admin.o
menu_admin.o:
	${CFLAGS} ${SRCDIR}/menu_admin.c -o ${OBJDIR}/menu_admin.o
menu_user.o:
	${CFLAGS} ${SRCDIR}/menu_user.c -o ${OBJDIR}/menu_user.o
clear.o:
	${CFLAGS} ${SRCDIR}/clear.c -o ${OBJDIR}/clear.o
finalexe:
	gcc ${OBJDIR}/main.o ${OBJDIR}/options.o ${OBJDIR}/admin.o ${OBJDIR}/menu_admin.o ${OBJDIR}/menu_user.o ${OBJDIR}/clear.o -o ${BINDIR}/main.exe
