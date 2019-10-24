COMPONENTS_SRC_DIR=$$PWD/src/components
COMPONENTS_INC_DIR=$$PWD/include/components

INCLUDEPATH += $$COMPONENTS_INC_DIR
INCLUDEPATH += $$COMPONENTS_SRC_DIR

SOURCES += \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialstyle.cpp \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialtheme.cpp \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialoverlaywidget.cpp \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialcheckable_internal.cpp \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialcheckable.cpp \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialripple.cpp \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialrippleoverlay.cpp \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialstatetransition.cpp \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialstyle_p.h \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialtheme_p.h \
    $$COMPONENTS_SRC_DIR/lib/qtmaterialcheckable_p.h \
#    $$COMPONENTS_SRC_DIR/layouts/qtmaterialsnackbarlayout_p.h \
#    $$COMPONENTS_SRC_DIR/layouts/qtmaterialsnackbarlayout.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialavatar.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialbadge.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialcheckbox.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialfab.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialraisedbutton.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialflatbutton_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialflatbutton.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialiconbutton.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialprogress_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialprogress.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialcircularprogress_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialcircularprogress.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialslider_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialslider.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialsnackbar_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialsnackbar.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialradiobutton.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialtoggle_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialtoggle.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialtextfield_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialtextfield.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialtabs_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialtabs.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialscrollbar_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialscrollbar.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialdialog_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialdialog.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialdrawer_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialdrawer.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialappbar.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialautocomplete.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialpaper.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialtable.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialautocomplete_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialmenu.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialmenu_internal.cpp \
    $$COMPONENTS_SRC_DIR/qtmateriallist.cpp \
    $$COMPONENTS_SRC_DIR/qtmateriallistitem.cpp \
    $$COMPONENTS_SRC_DIR/qtmaterialavatar_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialbadge_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialcheckbox_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialfab_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialraisedbutton_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialflatbutton_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialiconbutton_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialprogress_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialcircularprogress_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialslider_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialsnackbar_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialradiobutton_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialtoggle_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialtextfield_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialtabs_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialscrollbar_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialdialog_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialdrawer_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialappbar_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialautocomplete_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialpaper_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialtable_p.h \
    $$COMPONENTS_SRC_DIR/qtmaterialmenu_p.h \
    $$COMPONENTS_SRC_DIR/qtmateriallist_p.h \
    $$COMPONENTS_SRC_DIR/qtmateriallistitem_p.h

HEADERS += \
    $$COMPONENTS_INC_DIR/lib/qtmaterialstyle.h \
    $$COMPONENTS_INC_DIR/lib/qtmaterialtheme.h \
    $$COMPONENTS_INC_DIR/lib/qtmaterialoverlaywidget.h \
    $$COMPONENTS_INC_DIR/lib/qtmaterialcheckable_internal.h \
    $$COMPONENTS_INC_DIR/lib/qtmaterialripple.h \
    $$COMPONENTS_INC_DIR/lib/qtmaterialrippleoverlay.h \
    $$COMPONENTS_INC_DIR/lib/qtmaterialcheckable.h \
    $$COMPONENTS_INC_DIR/lib/qtmaterialstatetransition.h \
    $$COMPONENTS_INC_DIR/lib/qtmaterialstatetransitionevent.h \
#    $$COMPONENTS_INC_DIR/layouts/qtmaterialsnackbarlayout.h \
    $$COMPONENTS_INC_DIR/qtmaterialavatar.h \
    $$COMPONENTS_INC_DIR/qtmaterialbadge.h \
    $$COMPONENTS_INC_DIR/qtmaterialcheckbox.h \
    $$COMPONENTS_INC_DIR/qtmaterialfab.h \
    $$COMPONENTS_INC_DIR/qtmaterialraisedbutton.h \
    $$COMPONENTS_INC_DIR/qtmaterialflatbutton_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialflatbutton.h \
    $$COMPONENTS_INC_DIR/qtmaterialiconbutton.h \
    $$COMPONENTS_INC_DIR/qtmaterialprogress_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialprogress.h \
    $$COMPONENTS_INC_DIR/qtmaterialcircularprogress_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialcircularprogress.h \
    $$COMPONENTS_INC_DIR/qtmaterialslider_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialslider.h \
    $$COMPONENTS_INC_DIR/qtmaterialsnackbar_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialsnackbar.h \
    $$COMPONENTS_INC_DIR/qtmaterialradiobutton.h \
    $$COMPONENTS_INC_DIR/qtmaterialtoggle_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialtoggle.h \
    $$COMPONENTS_INC_DIR/qtmaterialtextfield_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialtextfield.h \
    $$COMPONENTS_INC_DIR/qtmaterialtabs_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialtabs.h \
    $$COMPONENTS_INC_DIR/qtmaterialscrollbar_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialscrollbar.h \
    $$COMPONENTS_INC_DIR/qtmaterialdialog_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialdialog.h \
    $$COMPONENTS_INC_DIR/qtmaterialdrawer_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialdrawer.h \
    $$COMPONENTS_INC_DIR/qtmaterialappbar.h \
    $$COMPONENTS_INC_DIR/qtmaterialautocomplete.h \
    $$COMPONENTS_INC_DIR/qtmaterialpaper.h \
    $$COMPONENTS_INC_DIR/qtmaterialtable.h \
    $$COMPONENTS_INC_DIR/qtmaterialautocomplete_internal.h \
    $$COMPONENTS_INC_DIR/qtmaterialmenu.h \
    $$COMPONENTS_INC_DIR/qtmaterialmenu_internal.h \
    $$COMPONENTS_INC_DIR/qtmateriallist.h \
    $$COMPONENTS_INC_DIR/qtmateriallistitem.h 

RESOURCES += \
    $$COMPONENTS_INC_DIR/resources.qrc
