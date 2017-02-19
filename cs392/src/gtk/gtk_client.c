/* Michael John
 * I pledge my Honor that I have abided by The Stevens Honor System
 * April 1, 2015
 */

#include "suckit2.h"
t_env gl_env;

void sigint(int sig)
{
  if(sig == SIGINT)
    {
      write(gl_env.sockfd, "/exit ", 6);
      my_panic("Goodbye\n", 0);
    }
}

void sigint_2(int sig)
{
  if(sig == SIGINT)
    {
      my_str("Goodbye\n");
      exit(0);
    }
}

gint ays_callback(GtkWidget *w, GdkEvent *e, gpointer data)
{
  GtkWidget *AYS_win;
  GtkWidget *AYS_yes_butt;
  GtkWidget *AYS_no_butt;
  GtkWidget *vbox;
  GtkWidget *top_hbox;
  GtkWidget *bot_hbox;
  GtkWidget *label;

  label = gtk_label_new("Are You Sure?");

  vbox = gtk_vbox_new(FALSE, 0);
  top_hbox = gtk_hbox_new(FALSE, 0);
  bot_hbox = gtk_hbox_new(FALSE, 0);
  
  AYS_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  AYS_yes_butt = gtk_button_new_with_label("Yes!");
  AYS_no_butt = gtk_button_new_with_label("No!");

  gtk_box_pack_start(GTK_BOX(bot_hbox), AYS_yes_butt, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(bot_hbox), AYS_no_butt, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(top_hbox), label, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(vbox), top_hbox, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(vbox), bot_hbox, TRUE, TRUE, 10);

  gtk_container_add(GTK_CONTAINER(AYS_win), vbox);
  gtk_container_set_border_width(GTK_CONTAINER(AYS_win), 10);

  g_signal_connect(G_OBJECT(AYS_win), "delete_event", G_CALLBACK(close_close), NULL);
  g_signal_connect(G_OBJECT(AYS_win), "destroy", G_CALLBACK(close_program), NULL);
  g_signal_connect(G_OBJECT(AYS_yes_butt), "clicked", G_CALLBACK(close_program), NULL);
  g_signal_connect(G_OBJECT(AYS_no_butt), "clicked", G_CALLBACK(close_close), NULL);

  gtk_widget_show(AYS_yes_butt);
  gtk_widget_show(AYS_no_butt);
  gtk_widget_show(label);
  gtk_widget_show(top_hbox);
  gtk_widget_show(bot_hbox);
  gtk_widget_show(vbox);
  gtk_widget_show(AYS_win);  
  return 1;
}

void connect_close(GtkWidget *w, gpointer data)
{
  
}

void toggle_button_callback (GtkWidget *widget, gpointer data) 
{
  
  GtkWidget *win;
  GtkWidget *host;
  GtkWidget *port;
  GtkWidget *nick;
  
  GtkWidget *host_name;
  GtkWidget *port_num;
  GtkWidget *nick_name;

  GtkWidget *okay;
  GtkWidget *cancel;

  GtkWidget *r_vbox;
  GtkWidget *l_vbox;
  GtkWidget *hbox;

  win = gtk_window_new(win);
  host = gtk_label_new("Host: ");
  port = gtk_label_new("Port: ");
  nick = gtk_label_new("Nickname: ");
  hbox = gtk_hbox_new(FALSE, 0);
  r_vbox = gtk_vbox_new(FALSE, 0);
  l_vbox = gtk_vbox_new(FALSE, 0);
  host_name = gtk_entry_new();
  port_num = gtk_entry_new();
  nick_name = gtk_entry_new();

  g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(close_close), NULL);
  g_signal_connect(G_OBJECT(okay), "clicked", G_CALLBACK(connect_close), NULL);
  g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(close_close), NULL);
  
  gtk_box_pack_start(GTK_BOX(r_vbox), host_name, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(r_vbox), port_name, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(r_vbox), nick_name, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(r_vbox), okay, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(l_vbox), host, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(l_vbox), port, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(l_vbox), nick, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(l_vbox), cancel, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(hbox), l_vbox, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(hbox), r_vbox, TRUE, TRUE, 10);

  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (widget))) 
    {
      gtk_widget_show(host);
      gtk_widget_show(port);
      gtk_widget_show(nick);
      gtk_widget_show(host_name);
      gtk_widget_show(port_name);
      gtk_widget_show(nick_name);
      gtk_widget_show(r_vbox);
      gtk_widget_show(l_vbox);
      gtk_widget_show(hbox);
      gtk_widget_show(win);
      /* If control reaches here, the toggle button is down */
      gl_env.nickname = (char*)gtk_entry_get_text(nick_name);
      gl_env.port = my_atoi((char*)gtk_entry_get_text(port_num));
      gl_env.brick = (char*)gtk_entry_get_text(host_name);
      connect_to_server(widget, data);
    } 
  else 
  {
    /* If control reaches here, the toggle button is up */
    write(gl_env.sockfd, "/exit", 6);
    close(gl_env.sockfd);
    my_panic("Goodbye\n", 0);
  }
}


gint close_close(GtkWidget *w, GdkEvent *e, gpointer data)
{
  /* closes the "are you sure" window without killing the program */
  gtk_widget_destroy(data);
  return 0;
}

void close_program(GtkWidget *w, gpointer data)
{
  write(gl_env.sockfd, "/exit", 6);
  close(gl_env.sockfd);
  gtk_main_quit();
}
/*
void connect_to_server(GtkWidget *widget, gpointer data)
{
  struct sockaddr_in srv;
  if(gl_env.port > 0 && gl_env.port < (1<<16)-1)
    {
      gl_env.sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if(gethostbyname(gl_env.brick) == NULL)
	{
	  my_str("This host doesn't exist\n");
	  //toggle the connect button up
	  gtk_widget_destroy(data);
	  return;
	}
      memset(&srv, 0, sizeof(srv));
      srv.sin_family = AF_INET;
      srv.sin_port = htons(port);
      memcpy(&srv.sin_addr.s_addr, gl_env.brick->h_addr, gl_env.brick->h_length);
      if((connect(gl_env.sockfd, (struct sockaddr*)&srv, sizeof(srv))) < 0)
	{
	  my_str("Couldn't connect to the sever\n");
	  gtk_widget_destroy(data);
	  return;
	}
      write(gl_env.sockfd, gl_env.nickname, MAX-1); //sends the nickname
    }
}
*/

void send_callback(GtkWidget *w, gpointer data)
{
  
}

int main (int argc, char* argv[])
{
  int n;
  GtkWidget *main_win;
  GtkWidget *main_connect_butt;
  GtkWidget *main_exit_butt;
  GtkWidget *main_send_butt;
  GtkWidget *vbox;
  GtkWidget *top;
  GtkWidget *bot;
  GtkWidget *text;
  gtk_init(&argc, &argv);

  signal(SIGINT, sigint_2);//ends the client be-4 we connect to srv  
  //if(argc == 3)
  //{

  text = gtk_entry_new();
  main_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  main_exit_butt = gtk_button_new_with_label("EXIT");
  main_connect_butt = gtk_toggle_button_new_with_label("Connect");
  main_send_butt = gtk_button_new_with_label("Send");

  vbox = gtk_vbox_new(FALSE, 0);
  top = gtk_hbox_new(FALSE, 0);
  bot = gtk_hbox_new(FALSE, 0);

  g_signal_connect(G_OBJECT(main_win), "delete_event", G_CALLBACK(ays_callback), NULL);
  g_signal_connect(G_OBJECT(main_exit_butt), "clicked", G_CALLBACK(ays_callback), NULL);
  g_signal_connect(G_OBJECT(main_connect_butt), "clicked", G_CALLBACK(toggle_button_callback), NULL);
  g_signal_connect(G_OBJECT(main_send_butt), "clicked", G_CALLBACK(send_callback), NULL);

  gtk_box_pack_start(GTK_BOX(bot), main_connect_butt, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(bot), main_exit_butt, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(top), text, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(top), main_send_butt, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(vbox), top, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), bot, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(main_win), vbox);

  gtk_widget_show(main_connect_butt);
  gtk_widget_show(main_send_butt);
  gtk_widget_show(main_exit_butt);
  gtk_widget_show(text);
  gtk_widget_show(bot);
  gtk_widget_show(top);
  gtk_widget_show(vbox);
  gtk_widget_show(main_win);

  gtk_main();
  return 0;
  /*
  g_signal_connect(G_OBJECT(main_connect_butt), "clicked", G_CALLBACK(toggle_button_callback), NULL);
  
  g_signal_connect(G_OBJECT(main_send_butt), "clicked", G_CALLBACK(send_callback), NULL);
  
  gtk_widget_show(main_connect_butt);
  gtk_widget_show(main_exit_butt);
  gtk_widget_show(main_send_butt);

  /*     	  signal(SIGINT, sigint);
	  usleep(2000);
	  n = read(gl_env.sockfd, nickname, MAX-1); // the sever's response
	  nickname[n] = '\0';
	  if(nickname[0] == '?')
	    {
	      while(1)
		{
		  my_char('~');
		  n = read(0, nickname, MAX-1);
		  nickname[n-1] = '\0';
		  if(my_strncmp(nickname, "/exit", 5) == 0 && (nickname[5]==' ' || nickname[5]=='\t' || nickname[5]=='\0' || nickname[5]=='\n'))
		    break;
		  write(gl_sockfd, nickname, MAX-1);
		  //my_str("Wrote to server\n");
		  usleep(2000);
		  n = read(gl_sockfd, nickname, MAX-1);
		  //my_str(nickname);
		  //my_char('\n');
		  if(nickname[0] != '?')
		    {
		      my_panic("You have been disconnected or the Server is down\n", 0);
		      return 0;
		    }
		}
	      write(gl_sockfd, "/exit", 6);
	      //usleep(2000);
	      my_panic("Goodbye\n", 0);
	      return 0;
	    }
	  else
	    {
	      my_panic("The Server is Down!\n", 1);
	      return 0;
	    }
	}
      else
	{
	  my_panic("Please provide a valid port number\n", 1);
	  return 0;
	}
    }
  else
    {
      my_panic("Usage: ./client server-machine-name PORT\n", 1);
      return 0;
      }*/
}
