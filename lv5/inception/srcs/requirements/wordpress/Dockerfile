FROM debian:bullseye

ENV PHP_VERSION=7.4

RUN apt-get update && apt-get install -y \
  php${PHP_VERSION}-fpm \
  php${PHP_VERSION}-mysql \
  wget unzip sudo

COPY php.ini /usr/local/etc/php/
COPY conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf
COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]

CMD [ "php-fpm7.4", "-F" ]
