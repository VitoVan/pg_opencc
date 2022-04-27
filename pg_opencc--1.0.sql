--complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION pg_opencc" to load this file. \quit

CREATE FUNCTION opencc_s2t(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_s2t'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_t2s(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_t2s'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_s2tw(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_s2tw'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_tw2s(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_tw2s'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_s2hk(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_s2hk'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_hk2s(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_hk2s'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_s2twp(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_s2twp'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_tw2sp(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_tw2sp'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_t2tw(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_t2tw'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_hk2t(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_hk2t'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_t2hk(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_t2hk'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_t2jp(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_t2jp'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_jp2t(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_jp2t'
    LANGUAGE C STRICT;


CREATE FUNCTION opencc_tw2t(text) RETURNS text
    AS 'MODULE_PATHNAME','opencc_tw2t'
    LANGUAGE C STRICT;
