CREATE DATABASE wordpress_db DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE USER 'boss'@'wordpress' IDENTIFIED BY 'b0ss_passW0rd';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'boss'@'wordpress';
CREATE USER 'hmiyazak'@'wordpress' IDENTIFIED BY 'harutoM1yazak1';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'hmiyazak'@'wordpress';
CREATE USER 'boss'@'127.0.0.1' IDENTIFIED BY 'b0ss_passW0rd';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'boss'@'127.0.0.1';
CREATE USER 'hmiyazak'@'127.0.0.1' IDENTIFIED BY 'harutoM1yazak1';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'hmiyazak'@'127.0.0.1';
FLUSH PRIVILEGES;