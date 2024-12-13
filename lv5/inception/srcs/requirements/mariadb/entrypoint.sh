#!/bin/bash
# entrypoint.sh

set -e

mkdir -p /run/mysqld  && chown -R mysql:mysql /run/mysqld && chmod 755 /run/mysqld
mkdir -p /var/log/mysql && chown -R mysql:mysql /var/log/mysql && chmod 755 /var/log/mysql
mkdir -p /var/lib/mysql && chown -R mysql:mysql /var/lib/mysql && rm -rf /var/lib/mysql/*
touch /docker-entrypoin

mariadb-install-db --user=mysql --datadir=/var/lib/mysql

INIT_FILE="/docker-entrypoint-initdb.d/init.sql"
chmod 755 $INIT_FILE

echo "ALTER USER root@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';" >> $INIT_FILE
echo "CREATE DATABASE $MYSQL_DATABASE DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;" >> $INIT_FILE
echo "CREATE USER 'boss'@'%' IDENTIFIED BY 'b0ss_passW0rd';" >> $INIT_FILE
echo "GRANT ALL PRIVILEGES ON wordpress_db.* TO 'boss'@'%';" >> $INIT_FILE
echo "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';" >> $INIT_FILE
echo "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';" >> $INIT_FILE
echo "FLUSH PRIVILEGES;" >> $INIT_FILE

exec "$@"
