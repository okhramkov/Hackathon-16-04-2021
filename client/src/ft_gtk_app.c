#include "../inc/client.h"

static void     fr_init_window(t_client *client)
{
    ft_login_window(client);
}

void    ft_gtk_app(t_client *client)
{
    gtk_init(NULL, NULL);

    fr_init_window(client);

    gtk_widget_show(client->ui->login); /////////////////

    gtk_main();
}
