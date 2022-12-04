FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -Wall -std=c99 main.c \
./service/buscar-usuarios.service.c \
./service/buscar-funcionarios.service.c \
./service/login-usuario.service.c \
./service/criar-usuario.service.c \
./service/criar-funcionario.service.c \
./service/criar-relatorio-funcionarios.service.c \
./service/criar-cliente.service.c \
./service/buscar-clientes.service.c \
./pages/menu.page.c \
./pages/login.page.c \
./pages/cadastro-usuario.page.c \
./pages/cadastro-funcionario.page.c \
./pages/perfil.page.c \
./pages/home.page.c \
./pages/buscar-usuarios.page.c \
./pages/buscar-funcionarios.page.c \
./pages/relatorios.page.c \
./pages/cadastro-cliente.page.c \
./pages/buscar-clientes.page.c \
./pages/consultas.page.c \
./pages/cadastros.page.c \
./utils/time.utils.c \
./utils/montar-caminho-arquivo.utils.c \
./utils/delay.utils.c \
./utils/voltar.utils.c \
./client/socket-client.c -o start
EXPOSE 3000
CMD ["./start"]