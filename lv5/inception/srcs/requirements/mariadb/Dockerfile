FROM mariadb

RUN apt update && apt install -y mariadb-server

# COPY ./docker-entrypoint.sh /

RUN mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld && \
    chmod 755 /run/mysqld

COPY ./conf /etc/mysql/conf.d/my.cnf
COPY ./init.sql /docker-entrypoint-initdb.d/

# RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

RUN chown -R mysql:mysql /var/lib/mysql

EXPOSE 3306

CMD [ "mariadbd", "--user=mysql", "--console" ]

# FROM debian:12

# RUN apt update && apt install -y mariadb-server

# RUN mkdir -p /run/mysqld && \
#     chown -R mysql:mysql /run/mysqld && \
#     chmod 755 /run/mysqld

# COPY ./conf /etc/mysql/conf.d/my.cnf
# COPY ./init.sql /docker-entrypoint-initdb.d/init.sql

# RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

# RUN chown -R mysql:mysql /var/lib/mysql

# EXPOSE 3306

# CMD [ "mariadbd", "--user=mysql", "--console" ]
