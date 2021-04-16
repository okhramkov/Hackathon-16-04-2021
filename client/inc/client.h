#pragma once

#include <stdio.h>
#include <gtk/gtk.h>
#include "../../frameworks/libmx/inc/libmx.h"
#include "cJSON.h"

#define LOGIN_CSS "client/data/style/login.css"

typedef struct s_ui {
    //login window
    GtkWidget   *login;
    GtkWidget   *username;
    GtkWidget   *password;
    GtkWidget   *button_reg;
    GtkWidget   *button_log;
}   t_ui;

typedef struct s_client {
    t_ui    *ui;
}   t_client;

void    ft_gtk_app(t_client *client);
void    ft_login_window(t_client *client);
