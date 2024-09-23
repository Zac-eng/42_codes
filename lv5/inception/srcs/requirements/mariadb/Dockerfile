FROM debian:12

RUN echo "mariadb-server mariadb-server/root_password password $MYSQL_ROOT_PASSWORD" | debconf-set-selections && \
    echo "mariadb-server mariadb-server/root_password_again password $MYSQL_ROOT_PASSWORD" | debconf-set-selections

RUN apt-get update && apt-get install -y \
    gnupg2 \
    lsb-release \
    ca-certificates \
    curl

RUN curl -sS https://downloads.mariadb.com/MariaDB/mariadb_repo_setup | bash && \
    apt-get update && apt-get install -y mariadb-server mariadb-client && \
    rm -rf /var/lib/apt/lists/*


RUN mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld && \
    chmod 755 /run/mysqld

RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

RUN chown -R mysql:mysql /var/lib/mysql

EXPOSE 3306

CMD [ "mariadbd", "--user=mysql", "--console" ]
