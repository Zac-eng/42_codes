FROM debian:12

RUN apt-get update && apt-get install -y gnupg2 curl

RUN curl -fsSL https://nginx.org/keys/nginx_signing.key | apt-key add -

RUN echo "deb http://nginx.org/packages/debian/ bookworm nginx" \
    | tee /etc/apt/sources.list.d/nginx.list

RUN apt update && apt install -y nginx

WORKDIR /var/www/html

RUN chown -R www-data:www-data /var/www/ \
&& chmod -R 755 /var/www/

COPY ./conf /etc/nginx/conf.d/default.conf
COPY ./credencials/server.nginx.pem /etc/nginx/ssl/server.nginx.pem
COPY ./credencials/server.key /etc/nginx/ssl/server.key

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]
