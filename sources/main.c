#include <jsapi.h>
#include <gtk/gtk.h>

int
main (int argc, char** argv)
{
    JSRuntime* runtime = JS_NewRuntime(8L * 1024L * 1024L);

    GtkWidget* win1;
    GtkWidget* win2;

    gtk_init(&argc, &argv);

    win1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    win2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_widget_show_all(win1);
    gtk_widget_show_all(win2);

    gtk_main();

    JS_DestroyRuntime(runtime);

    return 0;
}
