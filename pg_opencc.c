#include "postgres.h"
#include <string.h>
#include "utils/builtins.h"
#include "opencc.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(opencc_s2t);
PG_FUNCTION_INFO_V1(opencc_t2s);
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

char* opencc_convert (char* input, char config[]) {
    opencc_t opencc = opencc_open(config); // e.g.: config = "s2t.json"
    char* converted = opencc_convert_utf8(opencc, input, strlen(input));
    opencc_close(opencc);
    return converted;
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
