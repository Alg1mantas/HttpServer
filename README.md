# Simple C HTTP Server

This is a simple HTTP server implemented in C. The purpose of this project is to learn the fundamentals of how network programming works using sockets in C.

![HttpServer](server.jpg)

**Note: This project is not yet finished.**

## Purpose

The main objective of this project is to understand the basics of creating a server-client architecture, handling HTTP requests, and serving static content over the network. 

## Future Improvements

In the future, I plan to implement the following features and enhancements:
- Implement functionality for the server to read files from `.html` documents and serve them as web pages.
- Add robust error handling mechanisms to ensure the server handles unexpected scenarios gracefully.
- Improve code structure and organization for better maintainability and readability.
- Enhance security measures to protect against common web vulnerabilities.

## How to Use

1. Clone the repository:

    ```bash
    git clone git@github.com:Alg1mantas/HttpServer.git>
    ```

2. Navigate to the project directory:

    ```bash
    cd HttpServer
    ```

3. Compile the server code:

    ```bash
    gcc HttpServer.c -o httpserver
    ```

4. Run the server:

    ```bash
    sudo ./httpsever
    ```

5. Open your web browser and go to `http://127.0.0.1`.

6. You will see the server's welcoming message displayed in your browser, as shown above.


## Feedback and Contributions

Feedback and contributions are welcome! If you have any suggestions, improvements, or bug fixes, feel free to open an issue or submit a pull request.


