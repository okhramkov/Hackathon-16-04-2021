#include "../inc/client.h"

int main(int ac, char *av[]) {
    (void)ac;
    (void)av;

    t_client *client = (t_client *)malloc(sizeof(t_client));
    client->ui = (t_ui *)malloc(sizeof(t_ui));

    ft_gtk_app(client);

    return (0);
}
