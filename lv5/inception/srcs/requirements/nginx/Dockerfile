FROM debian:12

RUN apt update && apt install -y nginx

COPY ./conf /etc/nginx/conf.d/default.conf

EXPOSE 80

CMD [ "nginx", "-g", "daemon off;" ]