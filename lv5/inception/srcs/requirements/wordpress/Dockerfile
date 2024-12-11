FROM debian:12

ENV PHP_VERSION=8.2

RUN apt update && apt install -y \
  php${PHP_VERSION}-fpm \
  php${PHP_VERSION}-mysql \
  mariadb-client \
  wget unzip

COPY php.ini /usr/local/etc/php/
COPY conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf
COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]

CMD [ "php-fpm8.2", "-F" ]
