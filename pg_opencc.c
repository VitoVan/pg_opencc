#include "postgres.h"
#include <string.h>
#include "utils/builtins.h"
#include "tsearch/ts_public.h"
#include "lib/stringinfo.h"
#include "opencc.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(opencc_s2t);
PG_FUNCTION_INFO_V1(opencc_t2s);
PG_FUNCTION_INFO_V1(opencc_t2s_lexize);
PG_FUNCTION_INFO_V1(opencc_s2tw);
PG_FUNCTION_INFO_V1(opencc_tw2s);
PG_FUNCTION_INFO_V1(opencc_s2hk);
PG_FUNCTION_INFO_V1(opencc_hk2s);
PG_FUNCTION_INFO_V1(opencc_s2twp);
PG_FUNCTION_INFO_V1(opencc_tw2sp);
PG_FUNCTION_INFO_V1(opencc_t2tw);
PG_FUNCTION_INFO_V1(opencc_hk2t);
PG_FUNCTION_INFO_V1(opencc_t2hk);
PG_FUNCTION_INFO_V1(opencc_t2jp);
PG_FUNCTION_INFO_V1(opencc_jp2t);
PG_FUNCTION_INFO_V1(opencc_tw2t);

char* opencc_convert(char* input, char config[]);

Datum opencc_s2t (PG_FUNCTION_ARGS);
Datum opencc_t2s (PG_FUNCTION_ARGS);
Datum opencc_t2s_lexize (PG_FUNCTION_ARGS);
Datum opencc_s2tw (PG_FUNCTION_ARGS);
Datum opencc_tw2s (PG_FUNCTION_ARGS);
Datum opencc_s2hk (PG_FUNCTION_ARGS);
Datum opencc_hk2s (PG_FUNCTION_ARGS);
Datum opencc_s2twp (PG_FUNCTION_ARGS);
Datum opencc_tw2sp (PG_FUNCTION_ARGS);
Datum opencc_t2tw (PG_FUNCTION_ARGS);
Datum opencc_hk2t (PG_FUNCTION_ARGS);
Datum opencc_t2hk (PG_FUNCTION_ARGS);
Datum opencc_t2jp (PG_FUNCTION_ARGS);
Datum opencc_jp2t (PG_FUNCTION_ARGS);
Datum opencc_tw2t (PG_FUNCTION_ARGS);

void print_char_array(char *arr, size_t len) {
  ereport(LOG, (errmsg("PRINT_CHAR_ARRAY:")));
  for (size_t i = 0; i < len; ++i) {
    ereport(LOG, (errmsg("%d, ", arr[i])));
  }
  ereport(LOG, (errmsg("\n")));
}

char* opencc_convert (char* input, char config[]) {
    ereport(LOG, (errmsg("#****** FUCK 00: OPENCC_CON")));
    opencc_t opencc = opencc_open(config); // e.g.: config = "s2t.json"
    ereport(LOG, (errmsg("#****** FUCK 01: %s, SIZE: %d", input, strlen(input))));
    print_char_array(input, strlen(input));
    // const char* converted = opencc_convert_utf8(opencc, input, strlen(input));
    // char* converted = opencc_convert_utf8(opencc, input, pg_mblen(input));
    // ereport(LOG, (errmsg("#****** FUCK 02: %s, %d", converted, strlen(converted))));
    // print_char_array(converted, strlen(converted));
    // ereport(LOG, (errmsg("#****** FUCK 03: ERR(%s)", opencc_error())));
    // opencc_close(opencc);
    // ereport(LOG, (errmsg("#****** FUCK 04: OPENCC_CLOSE")));
    return opencc_convert_utf8(opencc, input, strlen(input));
}

Datum opencc_s2t (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "s2t.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_t2s (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "t2s.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_t2s_lexize (PG_FUNCTION_ARGS) {
  char* token = (char *) PG_GETARG_POINTER(1);
  ereport(LOG, (errmsg("#****** LEXIZE 00: %s, SIZE: %d", token, strlen(token))));
    
  const char* converted = opencc_convert(token, "t2s.json");

  ereport(LOG, (errmsg("#****** LEXIZE 01: %s, SIZE: %d", converted, strlen(converted))));
  
  StringInfoData buf;
  buf.data = NULL;
  initStringInfo(&buf);
  // appendBinaryStringInfo(&buf, converted, sizeof(converted));
  appendStringInfoString(&buf, converted);

  ereport(LOG, (errmsg("#****** LEXIZE 02: %s, SIZE: %d", buf.data, buf.len)));
  
  TSLexeme* res = (TSLexeme *) palloc0(sizeof(TSLexeme) * 2);

  ereport(LOG, (errmsg("#****** LEXIZE 03: %p", res)));
  
  res->lexeme = buf.data;
  res->flags = TSL_FILTER;

  PG_RETURN_POINTER(res);
}

Datum opencc_t2s_lexize_bak1 (PG_FUNCTION_ARGS) {
  char* token = (char *) PG_GETARG_POINTER(1);
  ereport(LOG, (errmsg("#****** LEXIZE 00: %s, SIZE: %d", token, strlen(token))));
    
  const char* converted = opencc_convert(token, "t2s.json");

  ereport(LOG, (errmsg("#****** LEXIZE 01: %s, SIZE: %d", converted, strlen(converted))));
  
  StringInfoData buf;
  buf.data = NULL;
  initStringInfo(&buf);
  // appendBinaryStringInfo(&buf, converted, sizeof(converted));
  appendStringInfoString(&buf, converted);

  ereport(LOG, (errmsg("#****** LEXIZE 02: %s, SIZE: %d", buf.data, buf.len)));
  
  TSLexeme* res = (TSLexeme *) palloc0(sizeof(TSLexeme) * 2);

  ereport(LOG, (errmsg("#****** LEXIZE 03: %p", res)));
  
  res->lexeme = buf.data;
  res->flags = TSL_FILTER;

  PG_RETURN_POINTER(res);
}

Datum opencc_t2s_lexize_bak0 (PG_FUNCTION_ARGS) {
  char* token = (char *) PG_GETARG_POINTER(1);
  char* converted = opencc_convert(token, "t2s.json");
  TSLexeme* res = (TSLexeme *) palloc0(sizeof(TSLexeme) * 2);
  res->lexeme = converted;
  res->flags = TSL_FILTER;

  PG_RETURN_POINTER(res);
}

Datum opencc_s2tw (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "s2tw.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_tw2s (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "tw2s.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_s2hk (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "s2hk.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_hk2s (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "hk2s.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_s2twp (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "s2twp.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_tw2sp (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "tw2sp.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_t2tw (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "t2tw.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_hk2t (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "hk2t.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_t2hk (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "t2hk.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_t2jp (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "t2jp.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_jp2t (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "jp2t.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}

Datum opencc_tw2t (PG_FUNCTION_ARGS) {
  char* arg1 = text_to_cstring(PG_GETARG_TEXT_PP(0));
  char* converted = opencc_convert(arg1, "tw2t.json");
  PG_RETURN_TEXT_P(cstring_to_text(converted));
}
