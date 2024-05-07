#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80
#define BUFFER 1024

char server_msg[] =
    "<!DOCTYPE html>"
    "<html lang='en'>"
    "<head>"
    "<meta charset='UTF-8'>"
    "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
    "<title>Welcome Message</title>"
    "<style>"
    "body {"
    "font-family: 'Arial', sans-serif;"
    "background-color: #f4f4f9;"
    "margin: 40px;"
    "text-align: center;"
    "}"
    "h1 {"
    "color: #333;"
    "}"
    "p {"
    "color: #666;"
    "font-size: 18px;"
    "}"
    ".container {"
    "background-color: #fff;"
    "border: 1px solid #ddd;"
    "padding: 20px;"
    "border-radius: 8px;"
    "box-shadow: 0 2px 6px rgba(0,0,0,0.1);"
    "display: inline-block;"
    "}"
    "footer {"
    "margin-top: 20px;"
    "font-size: 16px;"
    "color: #777;"
    "}"
    "</style>"
    "</head>"
    "<body>"
    "<div class='container'>"
    "<h1>Hello from the Server!</h1>"
    "<p>Welcome to our service. Thank you for connecting!</p>"
    "<footer>Server Time: <script>document.write(new Date().toLocaleTimeString());</script></footer>"
    "</div>"
    "</body>"
    "</html>";

int main()
{
    // Create socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for connections
    listen(server_socket, 100);

    // Accept connections
    struct sockaddr_in client_address;
    int client_socket, address_len = sizeof(client_address);
    char client_msg_buffer[BUFFER];

    while (1)
    {
        // Accept connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_len);
        read(client_socket, client_msg_buffer, BUFFER);
        send(client_socket, server_msg, sizeof(server_msg), 0);
        printf("\n\n%s\n", client_msg_buffer);
        close(client_socket);
    }

    return 0;
}
