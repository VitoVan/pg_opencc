--complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION pg_opencc" to load this file. \quit

-- 簡體到繁體
CREATE FUNCTION opencc_s2t(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_s2t'
    LANGUAGE C STRICT;

-- 繁體到簡體
CREATE FUNCTION opencc_t2s(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_t2s'
    LANGUAGE C STRICT;

-- 簡體到臺灣正體
CREATE FUNCTION opencc_s2tw(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_s2tw'
    LANGUAGE C STRICT;

-- 臺灣正體到簡體
CREATE FUNCTION opencc_tw2s(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_tw2s'
    LANGUAGE C STRICT;

-- 簡體到香港繁體
CREATE FUNCTION opencc_s2hk(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_s2hk'
    LANGUAGE C STRICT;

-- 香港繁體到簡體
CREATE FUNCTION opencc_hk2s(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_hk2s'
    LANGUAGE C STRICT;

-- 簡體到繁體（臺灣正體標準）並轉換爲臺灣常用詞彙
CREATE FUNCTION opencc_s2twp(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_s2twp'
    LANGUAGE C STRICT;

-- 繁體（臺灣正體標準）到簡體並轉換爲中國大陸常用詞彙
CREATE FUNCTION opencc_tw2sp(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_tw2sp'
    LANGUAGE C STRICT;

-- 繁體（OpenCC 標準）到臺灣正體
CREATE FUNCTION opencc_t2tw(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_t2tw'
    LANGUAGE C STRICT;

-- 香港繁體到繁體（OpenCC 標準）
CREATE FUNCTION opencc_hk2t(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_hk2t'
    LANGUAGE C STRICT;

-- 繁體（OpenCC 標準）到香港繁體
CREATE FUNCTION opencc_t2hk(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_t2hk'
    LANGUAGE C STRICT;

-- 繁體（OpenCC 標準，舊字體）到日文新字體
CREATE FUNCTION opencc_t2jp(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_t2jp'
    LANGUAGE C STRICT;

-- 日文新字體到繁體（OpenCC 標準，舊字體）
CREATE FUNCTION opencc_jp2t(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_jp2t'
    LANGUAGE C STRICT;

-- 臺灣正體到繁體（OpenCC 標準
CREATE FUNCTION opencc_tw2t(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_tw2t'
    LANGUAGE C STRICT;
