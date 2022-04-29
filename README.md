# pg_opencc

pg_opencc is a PostgreSQL extension for conversions between Traditional Chinese, Simplified Chinese and Japanese Kanji (Shinjitai).

PostgreSQL 中文簡繁轉換擴展，支持詞彙級別的轉換、異體字轉換和地區習慣用詞轉換（中國大陸、臺灣、香港、日本新字體）。

已驗證環境 Tested on:

- Ubuntu 21.10 / libopencc-dev 1.1.1 / PostgreSQL 13.6
- Fedora 35 / opencc-devel 1.1.2 / PostgreSQL 13.4

## Introduction 介紹

![pg_opencc](pg_opencc.png "pg_opencc")

本項目基於 Open Chinese Convert (OpenCC, 開放中文轉換)，支持當前所有預設配置文件。

This project supports all preset configuration files based on Open Chinese Convert (OpenCC, open Chinese conversion).


詳情請參見：

For the details, please check:

https://github.com/BYVoid/OpenCC

## Usage 使用

```sql
postgres=# CREATE EXTENSION pg_opencc;
CREATE EXTENSION
postgres=# SELECT opencc_s2t('汉字');
 opencc_s2t
------------
 漢字
(1 row)
```

查看所有支持的函數：

For the list of supported functions, check:

[pg_opencc--1.0.sql](./pg_opencc--1.0.sql)

## Installation 安裝

1. 確保目標機器上已經安裝好以下軟體：

    Make sure you have installed the following software:

   - Development files for PostgreSQL
   - PostgreSQL Server
   - Utility for directing compilation
   - GNU C compiler
   - Development files for opencc
   - Helper tool to manage compile and link flags for libraries
   - Git SCM (Optional 非必選)

    For Ubuntu:

    ```bash
    sudo apt install \
        postgresql \
        postgresql-server-dev-all \
        make \
        gcc \
        libopencc-dev \
        pkg-config \
        git
    ```

    For Fedora:

    ```bash
    sudo dnf install \
        postgresql-server \
        postgresql-server-devel \
        make \
        gcc \
        opencc-devel \
        pkgconf \
        redhat-rpm-config \
        git

    # init PostgreSQL
    sudo postgresql-setup --initdb
    # start service
    sudo systemctl start postgresql
    ```

2. 構建 Build & 安裝 Install

    ```bash
    # 下載源代碼 Download the source code
    git clone https://github.com/VitoVan/pg_opencc.git

    # 编译 Compile
    cd pg_opencc
    make

    # 安裝擴展
    sudo make install
    ```
    
3. 激活擴展

    ```bash
    # Bash Shell
    sudo -u postgres psql
    
    # SQL Shell
    postgres=# CREATE EXTENSION pg_opencc;
    CREATE EXTENSION
    ```
