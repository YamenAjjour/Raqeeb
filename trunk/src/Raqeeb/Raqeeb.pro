#-------------------------------------------------
#
# Project created by QtCreator 2011-08-11T16:52:55
#
#-------------------------------------------------

QT       += core gui sql

DESTDIR+= ../../bin
TARGET = Raqeeb
TEMPLATE = app


SOURCES += \
    BLL/userhandler.cpp \
    BLL/user.cpp \
    BLL/log.cpp \
    BLL/filehandler.cpp \
    DAL/salarycompdal.cpp \
    PRE/userhandlogdialog.cpp \
    PRE/mainwindow.cpp \
    PRE/detaileduserdialog.cpp \
    PRE/adduser.cpp \
    PRE/addleave.cpp \
    BLL/leave.cpp \
    DAL/leavedal.cpp \
    PRE/addleaveemp.cpp \
    main.cpp \
    BLL/empidmodel.cpp \
    PRE/addbounce.cpp \
    BLL/bounce.cpp \
    DAL/bouncedal.cpp \
    PRE/newsalary.cpp \
    PRE/employeeinfo.cpp \
    BLL/leavemodel.cpp \
    DAL/userdal.cpp \
    BLL/bouncemodel.cpp




HEADERS  += \
    BLL/userhandler.h \
    BLL/user.h \
    BLL/log.h \
    BLL/filehandler.h \
    DAL/userDAL.h \
    DAL/salarycompDAL.h \
    PRE/userhandlogdialog.h \
    PRE/mainwindow.h \
    PRE/detaileduserdialog.h \
    PRE/adduser.h \
    PRE/addleave.h \
    BLL/leave.h \
    DAL/leavedal.h \
    PRE/addleaveemp.h \
    BLL/empidmodel.h \
    PRE/addbounce.h \
    BLL/bounce.h \
    DAL/bouncedal.h \
    PRE/newsalary.h \
    PRE/employeeinfo.h \
    BLL/leavemodel.h \
    DAL/userdal.h \
    DAL/salarycompdal.h \
    BLL/bouncemodel.h



FORMS    += \
    PRE/userhandlogdialog.ui \
    PRE/mainwindow.ui \
    PRE/detaileduserdialog.ui \
    PRE/adduser.ui \
    PRE/addleave.ui \
    PRE/addleaveemp.ui \
    PRE/addbounce.ui \
    PRE/newsalary.ui \
    PRE/employeeinfo.ui


OBJECTS_DIR +=../../build/obj
MOC_DIR +=../../build/moc
UI_DIR += ../../build/ui

RESOURCES += \
    raqeebResource.qrc









































