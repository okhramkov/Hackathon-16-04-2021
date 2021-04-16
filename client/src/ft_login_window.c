#include "../inc/client.h"

static void     ft_glade_login_widget(GtkBuilder *builder, t_client *client);

void    ft_login_window(t_client *client)
{
    //---------- CSS Style ------------//
    GtkCssProvider *provider = gtk_css_provider_new();
    char *style = LOGIN_CSS;

    gtk_css_provider_load_from_path(provider, style, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                               GTK_STYLE_PROVIDER(provider),
                               GTK_STYLE_PROVIDER_PRIORITY_USER);
    client->ui->login = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(client->ui->login, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_resizable(GTK_WINDOW(client->ui->login), FALSE);
    gtk_window_set_position(GTK_WINDOW(client->ui->login), GTK_WIN_POS_CENTER);

    GtkWidget *fixed = gtk_fixed_new();
    gtk_widget_set_name(fixed, "fixed");
    gtk_container_add(GTK_CONTAINER(client->ui->login), fixed);
    gtk_widget_show_all(fixed);


    gtk_widget_show_all(client->ui->login);
    //----------------------------------//

    GtkBuilder *builder = gtk_builder_new_from_file("client/data/glade/login.glade");
    if (!builder)
        g_critical("Builder setting error\n");

    gtk_builder_connect_signals(builder, NULL);

    ft_glade_login_widget(builder, client);

    g_object_unref(builder);
}

static void     ft_glade_login_widget(GtkBuilder *builder, t_client *client)
{
    if (!builder) return;

    client->ui->login = GTK_WIDGET(gtk_builder_get_object(builder, "login"));
    if (!client->ui->login) g_critical("Builder login error\n");

    client->ui->username = GTK_WIDGET(gtk_builder_get_object(builder, "bx_username"));
    if (!client->ui->username) g_critical("Builder bx_username error\n");

    client->ui->password = GTK_WIDGET(gtk_builder_get_object(builder, "bx_password"));
    if (!client->ui->password) g_critical("Builder bx_password error\n");

    client->ui->button_reg = GTK_WIDGET(gtk_builder_get_object(builder, "bx_reg"));
    if (!client->ui->button_reg) g_critical("Builder bx_reg error\n");

    client->ui->button_log = GTK_WIDGET(gtk_builder_get_object(builder, "bx_log"));
    if (!client->ui->button_log) g_critical("Builder bx_log error\n");
}
