#!/bin/bash
# entrypoint.sh

mkdir -p /run/mysqld  && chown -R mysql:mysql /run/mysqld && chmod 755 /run/mysqld
mkdir -p /var/log/mysql && chown -R mysql:mysql /var/log/mysql && chmod 755 /var/log/mysql
mkdir -p /var/lib/mysql && chown -R mysql:mysql /var/lib/mysql && rm -rf /var/lib/mysql/*

mysql_install_db

exec "$@"
