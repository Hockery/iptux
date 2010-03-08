#ifndef DIALOGBASE_H
#define DIALOGBASE_H

#include "mess.h"

class DialogBase: public SessionAbstract {
public:
        DialogBase(GroupInfo *grp);
        virtual ~DialogBase();

protected:
        void InitSublayerGeneral();
        void ClearSublayerGeneral();

        void ClearHistoryTextView();
        void ScrollHistoryTextview();

        void ShowEnclosure();
        void AttachEnclosure(const GSList *list);
        
        /* UI general */
        GtkWidget *CreateInputArea();
        virtual GtkWidget *CreateEnclosureArea();
        virtual GtkWidget *CreateHistoryArea();
        virtual GtkWidget *CreateFileMenu();
        virtual GtkWidget *CreateHelpMenu();
        virtual GtkWidget *CreateEnclosureTree(GtkTreeModel *model);

        GtkTreeModel *CreateEnclosureModel();
        GSList *PickEnclosure(uint32_t fileattr);

        bool SendEnclosureMsg();
        virtual bool SendTextMsg() = 0;
        /* TODO: Group SendTextMsg need add Picture */
        void FeedbackMsg(const gchar *msg);
        virtual void BroadcastEnclosureMsg(GSList *list) {}

        // 回调部分
        static void DragDataReceived(DialogBase *dlgpr, GdkDragContext *context,
                                     gint x, gint y, GtkSelectionData *data,
                                     guint info, guint time);
        static void AttachRegular(DialogBase *dlgpr);
        static void AttachFolder(DialogBase *dlgpr);

        static void ClearHistoryBuffer(DialogBase *dlgpr);
        static void SendMessage(DialogBase *dlggrp);
        static gboolean WindowConfigureEvent(GtkWidget *window,
                                             GdkEventConfigure *event, GData **dtset);
        static void PanedDivideChanged(GtkWidget *paned, GParamSpec *pspec,
                                       GData **dtset);
protected:

        GData *widset;		//窗体集
	GData *mdlset;		//数据model集
	GData *dtset;		//通用数据集
	GtkAccelGroup *accel;	//快捷键组
	GroupInfo *grpinf;	//群组信息
};

#endif