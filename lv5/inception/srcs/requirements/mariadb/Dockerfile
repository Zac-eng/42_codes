FROM debian:12

RUN apt update && apt install -y mariadb-server

COPY ./conf /etc/mysql/conf.d/my.cnf

COPY ./entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

COPY ./init.sql /docker-entrypoint-initdb.d/
RUN chmod 755 /docker-entrypoint-initdb.d/init.sql

EXPOSE 3306

USER root

ENTRYPOINT ["/entrypoint.sh"]

CMD ["mysqld_safe"]
