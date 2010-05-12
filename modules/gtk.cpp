#include <fagadget.h>

#include <gtk/gtk.h>
#include <cairo.h>

extern "C" {

int
initialize (int* argc, char*** argv)
{
    return gtk_init_check(argc, argv);
}

#if 0

    gtk_init(&argc, &argv);

    GtkWidget* win1;
    GtkWidget* win2;

    win1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    win2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_widget_show_all(win1);
    gtk_widget_show_all(win2);

    gtk_main();
#endif

}
