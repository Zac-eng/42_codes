CREATE DATABASE wordpress_db DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE USER 'boss'@'%' IDENTIFIED BY 'b0ss_passW0rd';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'boss'@'%';
CREATE USER 'hmiyazak'@'%' IDENTIFIED BY 'harutoM1yazak1';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'hmiyazak'@'%';
FLUSH PRIVILEGES;
