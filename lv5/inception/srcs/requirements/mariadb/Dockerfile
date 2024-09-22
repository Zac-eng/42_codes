FROM debian:12

RUN apt update && apt install -y \
      mariadb-client \
      mariadb-server \
    && apt clean

EXPOSE 3306

USER root

CMD [ "mariadbd", "--user=root", "--console" ]
