/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "duala.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

/* Line number tracking */
extern int yylineno;

FILE *fichier_asm;
extern char current_id[100];
char affectation_var[100];
int etiquette_counter = 0;
int etiquette_stack[10];
int stack_ptr = 0;

/* String literal handling */
char string_literals[100][256];
char string_labels[100][50];
int is_string_expression = 0;
int string_count = 0;

/* For loop limit variables tracking */
int for_limit_count = 0;
int for_limit_labels[50];

#line 100 "duala.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "duala.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEBUT = 3,                      /* DEBUT  */
  YYSYMBOL_FIN = 4,                        /* FIN  */
  YYSYMBOL_TYPE_ENTIER = 5,                /* TYPE_ENTIER  */
  YYSYMBOL_LIRE = 6,                       /* LIRE  */
  YYSYMBOL_ECRIRE = 7,                     /* ECRIRE  */
  YYSYMBOL_SI = 8,                         /* SI  */
  YYSYMBOL_ALORS = 9,                      /* ALORS  */
  YYSYMBOL_SINON = 10,                     /* SINON  */
  YYSYMBOL_FINSI = 11,                     /* FINSI  */
  YYSYMBOL_MBELE = 12,                     /* MBELE  */
  YYSYMBOL_SALA = 13,                      /* SALA  */
  YYSYMBOL_SUKAMBELESE = 14,               /* SUKAMBELESE  */
  YYSYMBOL_SELON = 15,                     /* SELON  */
  YYSYMBOL_CAS = 16,                       /* CAS  */
  YYSYMBOL_DEFAUT = 17,                    /* DEFAUT  */
  YYSYMBOL_FINSELON = 18,                  /* FINSELON  */
  YYSYMBOL_SORTIR = 19,                    /* SORTIR  */
  YYSYMBOL_POUR = 20,                      /* POUR  */
  YYSYMBOL_DE = 21,                        /* DE  */
  YYSYMBOL_A = 22,                         /* A  */
  YYSYMBOL_PAS = 23,                       /* PAS  */
  YYSYMBOL_FINPOUR = 24,                   /* FINPOUR  */
  YYSYMBOL_REPETER = 25,                   /* REPETER  */
  YYSYMBOL_JUSQUA = 26,                    /* JUSQUA  */
  YYSYMBOL_AFFECTATION = 27,               /* AFFECTATION  */
  YYSYMBOL_EGAL = 28,                      /* EGAL  */
  YYSYMBOL_DIFFERENT = 29,                 /* DIFFERENT  */
  YYSYMBOL_SUP_EGAL = 30,                  /* SUP_EGAL  */
  YYSYMBOL_INF_EGAL = 31,                  /* INF_EGAL  */
  YYSYMBOL_SUPERIEUR = 32,                 /* SUPERIEUR  */
  YYSYMBOL_INFERIEUR = 33,                 /* INFERIEUR  */
  YYSYMBOL_PLUS = 34,                      /* PLUS  */
  YYSYMBOL_MOINS = 35,                     /* MOINS  */
  YYSYMBOL_FOIS = 36,                      /* FOIS  */
  YYSYMBOL_DIVISE = 37,                    /* DIVISE  */
  YYSYMBOL_MODULO = 38,                    /* MODULO  */
  YYSYMBOL_POINT_VIRGULE = 39,             /* POINT_VIRGULE  */
  YYSYMBOL_VIRGULE = 40,                   /* VIRGULE  */
  YYSYMBOL_PAREN_OUV = 41,                 /* PAREN_OUV  */
  YYSYMBOL_PAREN_FERM = 42,                /* PAREN_FERM  */
  YYSYMBOL_DEUX_POINTS = 43,               /* DEUX_POINTS  */
  YYSYMBOL_NOMBRE_ENTIER = 44,             /* NOMBRE_ENTIER  */
  YYSYMBOL_IDENTIFICATEUR = 45,            /* IDENTIFICATEUR  */
  YYSYMBOL_STRING_LITERAL = 46,            /* STRING_LITERAL  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_programme = 48,                 /* programme  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_bloc = 50,                      /* bloc  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_declarations = 52,              /* declarations  */
  YYSYMBOL_declaration = 53,               /* declaration  */
  YYSYMBOL_instructions = 54,              /* instructions  */
  YYSYMBOL_instruction = 55,               /* instruction  */
  YYSYMBOL_affectation = 56,               /* affectation  */
  YYSYMBOL_57_3 = 57,                      /* $@3  */
  YYSYMBOL_expression = 58,                /* expression  */
  YYSYMBOL_expression_arith = 59,          /* expression_arith  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_expression_comp = 61,           /* expression_comp  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_terme = 63,                     /* terme  */
  YYSYMBOL_facteur = 64,                   /* facteur  */
  YYSYMBOL_conditionnelle = 65,            /* conditionnelle  */
  YYSYMBOL_66_6 = 66,                      /* $@6  */
  YYSYMBOL_67_7 = 67,                      /* $@7  */
  YYSYMBOL_boucle_tant_que = 68,           /* boucle_tant_que  */
  YYSYMBOL_69_8 = 69,                      /* $@8  */
  YYSYMBOL_fin_boucle = 70,                /* fin_boucle  */
  YYSYMBOL_lecture = 71,                   /* lecture  */
  YYSYMBOL_ecriture = 72,                  /* ecriture  */
  YYSYMBOL_73_9 = 73,                      /* $@9  */
  YYSYMBOL_74_10 = 74,                     /* $@10  */
  YYSYMBOL_structure_selon = 75,           /* structure_selon  */
  YYSYMBOL_76_11 = 76,                     /* $@11  */
  YYSYMBOL_liste_cas = 77,                 /* liste_cas  */
  YYSYMBOL_cas_simple = 78,                /* cas_simple  */
  YYSYMBOL_79_12 = 79,                     /* $@12  */
  YYSYMBOL_partie_defaut_opt = 80,         /* partie_defaut_opt  */
  YYSYMBOL_81_13 = 81,                     /* $@13  */
  YYSYMBOL_sortir_instruction = 82,        /* sortir_instruction  */
  YYSYMBOL_boucle_pour = 83,               /* boucle_pour  */
  YYSYMBOL_pas_opt = 84,                   /* pas_opt  */
  YYSYMBOL_boucle_pour_init = 85,          /* boucle_pour_init  */
  YYSYMBOL_boucle_repeter = 86,            /* boucle_repeter  */
  YYSYMBOL_87_14 = 87                      /* $@14  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    48,   119,   119,   129,   131,   135,   141,
     143,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   160,   160,   171,   172,   176,   177,   177,   184,   194,
     194,   203,   212,   221,   230,   239,   251,   252,   259,   267,
     278,   283,   288,   304,   311,   319,   311,   339,   339,   352,
     359,   369,   383,   386,   383,   407,   407,   421,   422,   426,
     426,   442,   444,   444,   451,   459,   483,   487,   495,   531,
     531
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEBUT", "FIN",
  "TYPE_ENTIER", "LIRE", "ECRIRE", "SI", "ALORS", "SINON", "FINSI",
  "MBELE", "SALA", "SUKAMBELESE", "SELON", "CAS", "DEFAUT", "FINSELON",
  "SORTIR", "POUR", "DE", "A", "PAS", "FINPOUR", "REPETER", "JUSQUA",
  "AFFECTATION", "EGAL", "DIFFERENT", "SUP_EGAL", "INF_EGAL", "SUPERIEUR",
  "INFERIEUR", "PLUS", "MOINS", "FOIS", "DIVISE", "MODULO",
  "POINT_VIRGULE", "VIRGULE", "PAREN_OUV", "PAREN_FERM", "DEUX_POINTS",
  "NOMBRE_ENTIER", "IDENTIFICATEUR", "STRING_LITERAL", "$accept",
  "programme", "$@1", "bloc", "$@2", "declarations", "declaration",
  "instructions", "instruction", "affectation", "$@3", "expression",
  "expression_arith", "$@4", "expression_comp", "$@5", "terme", "facteur",
  "conditionnelle", "$@6", "$@7", "boucle_tant_que", "$@8", "fin_boucle",
  "lecture", "ecriture", "$@9", "$@10", "structure_selon", "$@11",
  "liste_cas", "cas_simple", "$@12", "partie_defaut_opt", "$@13",
  "sortir_instruction", "boucle_pour", "pas_opt", "boucle_pour_init",
  "boucle_repeter", "$@14", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,  -100,     3,  -100,  -100,    13,    35,  -100,    -3,  -100,
    -100,    10,   125,  -100,    17,  -100,    25,    26,    27,    31,
      24,  -100,   -40,  -100,    44,  -100,  -100,  -100,    33,   -19,
    -100,   -18,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
      50,  -100,    36,   -40,   -40,   -40,   -40,  -100,    53,  -100,
    -100,    34,    51,  -100,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,    64,  -100,  -100,    37,
      38,    43,   -40,    19,  -100,   -40,    -5,    -5,    -5,    -5,
      -5,    -5,   -18,   -18,  -100,  -100,  -100,  -100,  -100,    47,
      83,    78,  -100,    71,    54,    57,  -100,  -100,    82,  -100,
    -100,  -100,    84,   -40,   -40,  -100,  -100,   125,  -100,   -40,
      16,  -100,  -100,    56,    89,    97,    65,    67,  -100,    95,
      75,  -100,    76,  -100,  -100,  -100,  -100,   125,  -100,  -100,
    -100,  -100,   107,   140,   125,  -100,    80,    30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     2,     0,     6,     1,     0,     4,     3,     0,     9,
       7,     0,     5,     8,     0,    52,     0,     0,     0,     0,
       0,    69,     0,    40,    41,    42,    10,    11,     0,    23,
      24,    25,    36,    14,    17,    12,    13,    15,    16,    18,
      66,    19,     0,     0,     0,     0,     0,    64,     0,     9,
      41,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    53,     0,
       0,     0,     0,     0,    43,     0,    32,    33,    35,    34,
      29,    31,    26,    28,    37,    38,    39,    67,     9,     0,
       0,     0,    55,     0,     0,     0,    30,    27,     0,    54,
      44,    47,     0,     0,     0,    22,    65,     0,     9,     0,
      61,    57,    68,     0,     0,     0,     0,     0,    58,     0,
       0,    45,    49,    59,    62,    56,    70,     0,    50,    48,
       9,     9,     0,     0,    63,    46,     0,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,  -100,  -100,  -100,  -100,  -100,   -47,   -99,  -100,
    -100,   -22,     0,  -100,  -100,  -100,    -9,   -27,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,    11,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     9,     6,    10,    12,    26,    27,
      52,    28,    29,    97,    30,    96,    31,    32,    33,   107,
     127,    34,   108,   129,    35,    36,    43,    89,    37,   102,
     110,   111,   130,   119,   131,    38,    39,    66,    40,    41,
      49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    22,    73,     4,    23,    50,    25,     1,   114,    54,
      55,    56,    57,    58,    59,    60,    61,     7,    62,    63,
      64,    68,    69,    70,    71,    14,    15,    16,   132,    60,
      61,    17,   109,   117,    18,    84,    85,    86,    19,    20,
       8,    98,    11,    87,    21,    94,   -60,   -60,   -60,    13,
      93,    82,    83,    95,    76,    77,    78,    79,    80,    81,
      22,   115,    42,    23,    24,    25,    44,    45,    46,    48,
      47,   -21,    53,    65,    72,    67,    74,    88,    75,    90,
      91,   112,   113,   133,   134,    92,    99,   116,    14,    15,
      16,   101,   100,   103,    17,   104,   105,    18,   120,   121,
     109,    19,    20,    14,    15,    16,   106,    21,   123,    17,
     124,   122,    18,   125,   126,   128,    19,    20,   135,   137,
       0,   118,    21,    22,     0,     0,    23,    24,    25,     0,
       0,    14,    15,    16,     0,     0,     0,    17,    22,     0,
      18,    23,    24,    25,    19,    20,    14,    15,    16,     0,
      21,     0,    17,     0,     0,    18,     0,     0,     0,   136,
      20,     0,     0,     0,     0,    21,    22,     0,     0,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,    23,    24,    25
};

static const yytype_int16 yycheck[] =
{
      22,    41,    49,     0,    44,    45,    46,     3,   107,    28,
      29,    30,    31,    32,    33,    34,    35,     4,    36,    37,
      38,    43,    44,    45,    46,     6,     7,     8,   127,    34,
      35,    12,    16,    17,    15,    62,    63,    64,    19,    20,
       5,    88,    45,    65,    25,    26,    16,    17,    18,    39,
      72,    60,    61,    75,    54,    55,    56,    57,    58,    59,
      41,   108,    45,    44,    45,    46,    41,    41,    41,    45,
      39,    27,    39,    23,    21,    39,    42,    13,    27,    42,
      42,   103,   104,   130,   131,    42,    39,   109,     6,     7,
       8,    13,     9,    22,    12,    41,    39,    15,    42,    10,
      16,    19,    20,     6,     7,     8,    24,    25,    43,    12,
      43,    14,    15,    18,    39,    39,    19,    20,    11,    39,
      -1,   110,    25,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,     6,     7,     8,    -1,    -1,    -1,    12,    41,    -1,
      15,    44,    45,    46,    19,    20,     6,     7,     8,    -1,
      25,    -1,    12,    -1,    -1,    15,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    25,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    44,    45,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    48,    49,     0,    50,    52,     4,     5,    51,
      53,    45,    54,    39,     6,     7,     8,    12,    15,    19,
      20,    25,    41,    44,    45,    46,    55,    56,    58,    59,
      61,    63,    64,    65,    68,    71,    72,    75,    82,    83,
      85,    86,    45,    73,    41,    41,    41,    39,    45,    87,
      45,    58,    57,    39,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    23,    84,    39,    58,    58,
      58,    58,    21,    54,    42,    27,    59,    59,    59,    59,
      59,    59,    63,    63,    64,    64,    64,    58,    13,    74,
      42,    42,    42,    58,    26,    58,    62,    60,    54,    39,
       9,    13,    76,    22,    41,    39,    24,    66,    69,    16,
      77,    78,    58,    58,    55,    54,    58,    17,    78,    80,
      42,    10,    14,    43,    43,    18,    39,    67,    39,    70,
      79,    81,    55,    54,    54,    11,    19,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    49,    48,    51,    50,    52,    52,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    57,    56,    58,    58,    59,    60,    59,    59,    62,
      61,    61,    61,    61,    61,    61,    63,    63,    63,    63,
      64,    64,    64,    64,    66,    67,    65,    69,    68,    70,
      70,    71,    73,    74,    72,    76,    75,    77,    77,    79,
      78,    80,    81,    80,    82,    83,    84,    84,    85,    87,
      86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     3,     0,     2,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     5,     1,     1,     1,     0,     4,     3,     0,
       4,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     1,     1,     3,     0,     0,    11,     0,     9,     0,
       1,     3,     0,     0,     5,     0,     8,     1,     2,     0,
       7,     0,     0,     4,     2,     5,     0,     2,     6,     0,
       8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 48 "duala.y"
          { 
        fichier_asm = fopen("programme.asm", "w");
        fprintf(fichier_asm, "; Programme en duala compile\n");
        fprintf(fichier_asm, "section .data\n");
        fprintf(fichier_asm, "    format_int db '%%d', 10, 0\n");
        fprintf(fichier_asm, "    format_str db '%%s', 10, 0\n");
        fprintf(fichier_asm, "    input_format db '%%d', 0\n");
        fprintf(fichier_asm, "    input_msg db 'Tɔlɛ ndambo: ', 0\n");
        printf("Mbɔmbɔ compilation...\n");
    }
#line 1292 "duala.tab.c"
    break;

  case 3: /* programme: DEBUT $@1 bloc FIN  */
#line 59 "duala.y"
        { 
        /* Add proper function epilogue */
        fprintf(fichier_asm, "    ; Fin du programme\n");
        fprintf(fichier_asm, "    mov eax, 0          ; Code de retour 0 (succès)\n");
        fprintf(fichier_asm, "    mov esp, ebp        ; Restauration du pointeur de pile\n");
        fprintf(fichier_asm, "    pop ebp             ; Restauration du pointeur de base\n");
        fprintf(fichier_asm, "    ret                 ; Retour au système d'exploitation\n");
        
        /* Add string literals and for loop variables to data section by reopening and inserting */
        if (string_count > 0 || for_limit_count > 0) {
            fclose(fichier_asm);
            
            /* Read the entire file */
            FILE *read_file = fopen("programme.asm", "r");
            fseek(read_file, 0, SEEK_END);
            long file_size = ftell(read_file);
            fseek(read_file, 0, SEEK_SET);
            
            char *content = malloc(file_size + 1);
            fread(content, 1, file_size, read_file);
            content[file_size] = '\0';
            fclose(read_file);
            
            /* Find where to insert strings (before section .text) */
            char *text_section = strstr(content, "section .text");
            if (text_section) {
                /* Rewrite file with strings and variables */
                fichier_asm = fopen("programme.asm", "w");
                
                /* Write everything before section .text */
                size_t before_text = text_section - content;
                fwrite(content, 1, before_text, fichier_asm);
                
                /* Add string definitions */
                for (int i = 0; i < string_count; i++) {
                    fprintf(fichier_asm, "    %s db %s, 0\n", string_labels[i], string_literals[i]);
                }
                
                /* Add for loop limit and step variables */
                for (int i = 0; i < for_limit_count; i++) {
                    fprintf(fichier_asm, "    limite_pour_%d dd 0\n", for_limit_labels[i]);
                    fprintf(fichier_asm, "    pas_pour_%d dd 0\n", for_limit_labels[i]);
                }
                
                fprintf(fichier_asm, "\n");
                
                /* Write the rest (section .text onwards) */
                fprintf(fichier_asm, "%s", text_section);
                
                fclose(fichier_asm);
            }
            free(content);
        } else {
            fclose(fichier_asm);
        }
        printf("Compilation suka na malamu!\n"); 
    }
#line 1354 "duala.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 119 "duala.y"
                 { 
        fprintf(fichier_asm, "\nsection .text\n");
        fprintf(fichier_asm, "    global main\n");
        fprintf(fichier_asm, "    extern printf, scanf\n");
        fprintf(fichier_asm, "main:\n");
        fprintf(fichier_asm, "    push ebp\n");
        fprintf(fichier_asm, "    mov ebp, esp\n");
    }
#line 1367 "duala.tab.c"
    break;

  case 8: /* declaration: TYPE_ENTIER IDENTIFICATEUR POINT_VIRGULE  */
#line 135 "duala.y"
                                             {
        fprintf(fichier_asm, "    %s dd 0\n", current_id);
        printf("Variable declaree: %s\n", current_id);
    }
#line 1376 "duala.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 160 "duala.y"
                   {
        strcpy(affectation_var, current_id);
    }
#line 1384 "duala.tab.c"
    break;

  case 22: /* affectation: IDENTIFICATEUR $@3 AFFECTATION expression POINT_VIRGULE  */
#line 162 "duala.y"
                                           {
        fprintf(fichier_asm, "    ; Affectation a %s\n", affectation_var);
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    mov [%s], eax\n", affectation_var);
        printf("Affectation a: %s\n", affectation_var);
    }
#line 1395 "duala.tab.c"
    break;

  case 23: /* expression: expression_arith  */
#line 171 "duala.y"
                     { printf("PARSER: expression -> expression_arith\n"); }
#line 1401 "duala.tab.c"
    break;

  case 24: /* expression: expression_comp  */
#line 172 "duala.y"
                      { printf("PARSER: expression -> expression_comp\n"); }
#line 1407 "duala.tab.c"
    break;

  case 25: /* expression_arith: terme  */
#line 176 "duala.y"
          { printf("PARSER: expression_arith -> terme\n"); }
#line 1413 "duala.tab.c"
    break;

  case 26: /* $@4: %empty  */
#line 177 "duala.y"
                                  { printf("PARSER: expression_arith -> expression_arith PLUS terme\n"); }
#line 1419 "duala.tab.c"
    break;

  case 27: /* expression_arith: expression_arith PLUS terme $@4  */
#line 177 "duala.y"
                                                                                                           {
        fprintf(fichier_asm, "    ; Addition\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    add eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1431 "duala.tab.c"
    break;

  case 28: /* expression_arith: expression_arith MOINS terme  */
#line 184 "duala.y"
                                   {
        fprintf(fichier_asm, "    ; Soustraction\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    sub eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1443 "duala.tab.c"
    break;

  case 29: /* $@5: %empty  */
#line 194 "duala.y"
                                                { printf("PARSER: expression_comp -> expression_arith SUPERIEUR expression_arith\n"); }
#line 1449 "duala.tab.c"
    break;

  case 30: /* expression_comp: expression_arith SUPERIEUR expression_arith $@5  */
#line 194 "duala.y"
                                                                                                                                        {
        fprintf(fichier_asm, "    ; Comparaison >\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setg al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1463 "duala.tab.c"
    break;

  case 31: /* expression_comp: expression_arith INFERIEUR expression_arith  */
#line 203 "duala.y"
                                                  {
        fprintf(fichier_asm, "    ; Comparaison <\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setl al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1477 "duala.tab.c"
    break;

  case 32: /* expression_comp: expression_arith EGAL expression_arith  */
#line 212 "duala.y"
                                             {
        fprintf(fichier_asm, "    ; Comparaison ==\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    sete al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1491 "duala.tab.c"
    break;

  case 33: /* expression_comp: expression_arith DIFFERENT expression_arith  */
#line 221 "duala.y"
                                                  {
        fprintf(fichier_asm, "    ; Comparaison !=\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setne al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1505 "duala.tab.c"
    break;

  case 34: /* expression_comp: expression_arith INF_EGAL expression_arith  */
#line 230 "duala.y"
                                                 {
        fprintf(fichier_asm, "    ; Comparaison <=\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setle al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1519 "duala.tab.c"
    break;

  case 35: /* expression_comp: expression_arith SUP_EGAL expression_arith  */
#line 239 "duala.y"
                                                 {
        fprintf(fichier_asm, "    ; Comparaison >=\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setge al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1533 "duala.tab.c"
    break;

  case 37: /* terme: terme FOIS facteur  */
#line 252 "duala.y"
                         {
        fprintf(fichier_asm, "    ; Multiplication\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    imul eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1545 "duala.tab.c"
    break;

  case 38: /* terme: terme DIVISE facteur  */
#line 259 "duala.y"
                           {
        fprintf(fichier_asm, "    ; Division\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1558 "duala.tab.c"
    break;

  case 39: /* terme: terme MODULO facteur  */
#line 267 "duala.y"
                           {
        fprintf(fichier_asm, "    ; Modulo\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push edx\n");
    }
#line 1571 "duala.tab.c"
    break;

  case 40: /* facteur: NOMBRE_ENTIER  */
#line 278 "duala.y"
                  {
        fprintf(fichier_asm, "    ; Constante %d\n", yylval);
        fprintf(fichier_asm, "    push %d\n", yylval);
        printf("Constante: %d\n", yylval);
    }
#line 1581 "duala.tab.c"
    break;

  case 41: /* facteur: IDENTIFICATEUR  */
#line 283 "duala.y"
                     {
        fprintf(fichier_asm, "    ; Variable %s\n", current_id);
        fprintf(fichier_asm, "    push dword [%s]\n", current_id);
        printf("Variable utilisee: %s\n", current_id);
    }
#line 1591 "duala.tab.c"
    break;

  case 42: /* facteur: STRING_LITERAL  */
#line 288 "duala.y"
                     {
        char string_label[50];
        sprintf(string_label, "str_%d", string_count);
        
        /* Store string literal for later addition to data section */
        strcpy(string_literals[string_count], current_id);
        strcpy(string_labels[string_count], string_label);
        string_count++;
        
        /* Mark this as a string expression */
        is_string_expression = 1;
        
        fprintf(fichier_asm, "    ; Chaine %s\n", current_id);
        fprintf(fichier_asm, "    push %s\n", string_label);
        printf("Chaine: %s\n", current_id);
    }
#line 1612 "duala.tab.c"
    break;

  case 43: /* facteur: PAREN_OUV expression PAREN_FERM  */
#line 304 "duala.y"
                                      {
        /* Parenthesized expression - nothing extra to do */
        printf("Expression parenthesee\n");
    }
#line 1621 "duala.tab.c"
    break;

  case 44: /* $@6: %empty  */
#line 311 "duala.y"
                                             {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "    ; Debut SI\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz sinon_%d\n", etiq);  /* Saut vers SINON si condition fausse */
        printf("Mbɔmbɔ condition SƆ\n");
    }
#line 1635 "duala.tab.c"
    break;

  case 45: /* $@7: %empty  */
#line 319 "duala.y"
                        {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_si_%d\n", etiq);  /* Saut par-dessus le SINON */
        fprintf(fichier_asm, "sinon_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Debut SINON\n");
        printf("Partie KƐMA\n");
    }
#line 1647 "duala.tab.c"
    break;

  case 46: /* conditionnelle: SI PAREN_OUV expression PAREN_FERM ALORS $@6 instruction SINON $@7 instruction FINSI  */
#line 325 "duala.y"
                        {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_si_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin SI\n");
        printf("Suka condition SƆ\n");
    }
#line 1658 "duala.tab.c"
    break;

  case 47: /* $@8: %empty  */
#line 339 "duala.y"
                                               {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "debut_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Debut MBELE\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz fin_boucle_%d\n", etiq);
        printf("Mbombɔ boucle MBELE\n");
    }
#line 1673 "duala.tab.c"
    break;

  case 49: /* fin_boucle: %empty  */
#line 352 "duala.y"
                {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    jmp debut_boucle_%d\n", etiq);
        fprintf(fichier_asm, "fin_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin MBELE\n");
        printf("Suka boucle MBELE\n");
    }
#line 1685 "duala.tab.c"
    break;

  case 50: /* fin_boucle: POINT_VIRGULE  */
#line 359 "duala.y"
                    {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    jmp debut_boucle_%d\n", etiq);
        fprintf(fichier_asm, "fin_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin MBELE\n");
        printf("Suka boucle MBELE (with semicolon)\n");
    }
#line 1697 "duala.tab.c"
    break;

  case 51: /* lecture: LIRE IDENTIFICATEUR POINT_VIRGULE  */
#line 369 "duala.y"
                                      {
        fprintf(fichier_asm, "    ; Lecture de %s\n", current_id);
        fprintf(fichier_asm, "    push input_msg\n");
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 4\n");
        fprintf(fichier_asm, "    push %s\n", current_id);
        fprintf(fichier_asm, "    push input_format\n");
        fprintf(fichier_asm, "    call scanf\n");
        fprintf(fichier_asm, "    add esp, 8          ; Restauration de la pile après scanf\n");
        printf("Yɛnɛ: %s\n", current_id);
    }
#line 1713 "duala.tab.c"
    break;

  case 52: /* $@9: %empty  */
#line 383 "duala.y"
           { 
        printf("PARSER: [ECRIRE] Start of ECRIRE statement at line %d\n", yylineno);
        printf("PARSER: [ECRIRE] Current token: %d\n", yychar);
    }
#line 1722 "duala.tab.c"
    break;

  case 53: /* $@10: %empty  */
#line 386 "duala.y"
                 { 
        printf("PARSER: [ECRIRE] Successfully parsed expression\n");
        printf("PARSER: [ECRIRE] Next token (expecting POINT_VIRGULE): %d\n", yychar);
    }
#line 1731 "duala.tab.c"
    break;

  case 54: /* ecriture: ECRIRE $@9 expression $@10 POINT_VIRGULE  */
#line 389 "duala.y"
                    {
        printf("PARSER: [ECRIRE] Found POINT_VIRGULE after expression\n");
        fprintf(fichier_asm, "    ; Ecriture\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    push eax\n");
        if (is_string_expression) {
            fprintf(fichier_asm, "    push format_str\n");
            is_string_expression = 0; /* Reset flag */
        } else {
            fprintf(fichier_asm, "    push format_int\n");
        }
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 8          ; Restauration de la pile après printf\n");
        printf("Kɔma expression\n");
    }
#line 1751 "duala.tab.c"
    break;

  case 55: /* $@11: %empty  */
#line 407 "duala.y"
                                          {
        fprintf(fichier_asm, "    ; NDƆŊ (switch)\n");
        fprintf(fichier_asm, "    pop eax\n");
        etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiquette_counter;
        printf("🔀 NDƆŊ (switch)\n");
    }
#line 1763 "duala.tab.c"
    break;

  case 56: /* structure_selon: SELON PAREN_OUV expression PAREN_FERM $@11 liste_cas partie_defaut_opt FINSELON  */
#line 413 "duala.y"
                                           {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_selon_%d:\n", etiq);
        printf("🔚 Suka NDƆŊ\n");
    }
#line 1773 "duala.tab.c"
    break;

  case 59: /* $@12: %empty  */
#line 426 "duala.y"
                               {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    ; Cas\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        etiquette_counter++;
        fprintf(fichier_asm, "    jne cas_suivant_%d\n", etiquette_counter);
        printf("📋 KƐS\n");
    }
#line 1787 "duala.tab.c"
    break;

  case 60: /* cas_simple: CAS expression DEUX_POINTS $@12 instructions SORTIR POINT_VIRGULE  */
#line 434 "duala.y"
                                        {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq);
        fprintf(fichier_asm, "cas_suivant_%d:\n", etiquette_counter);
        printf("🙪 BIMA (break)\n");
    }
#line 1798 "duala.tab.c"
    break;

  case 62: /* $@13: %empty  */
#line 444 "duala.y"
                         {
        fprintf(fichier_asm, "    ; CAS DEFAUT\n");
        printf("📋 KƐS BƆSƆ\n");
    }
#line 1807 "duala.tab.c"
    break;

  case 64: /* sortir_instruction: SORTIR POINT_VIRGULE  */
#line 451 "duala.y"
                         {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq);
        printf("🚪 BIMA (break)\n");
    }
#line 1817 "duala.tab.c"
    break;

  case 65: /* boucle_pour: boucle_pour_init pas_opt SALA instructions FINPOUR  */
#line 459 "duala.y"
                                                       {
        int etiq = etiquette_stack[stack_ptr-1];  // Don't pop yet, we still need it
        char *var = current_id;
        
        // Generate the loop increment and condition check
        fprintf(fichier_asm, "    ; Incrémentation du compteur et vérification de la condition\n");
        
        // Increment the loop variable
        fprintf(fichier_asm, "    mov eax, [%s]\n", var);
        fprintf(fichier_asm, "    add eax, 1  ; Incrémenter la variable de boucle\n");
        fprintf(fichier_asm, "    mov [%s], eax\n", var);
        
        // Jump back to the start of the loop
        fprintf(fichier_asm, "    jmp debut_pour_%d\n", etiq);
        
        // End of loop label
        fprintf(fichier_asm, "fin_pour_%d:\n", etiq);
        
        // Pop the loop counter from the stack
        stack_ptr--;
        printf("<- Fin POUR\n");
    }
#line 1844 "duala.tab.c"
    break;

  case 66: /* pas_opt: %empty  */
#line 483 "duala.y"
                                        {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    ; Using default step of 1\n");
    }
#line 1853 "duala.tab.c"
    break;

  case 67: /* pas_opt: PAS expression  */
#line 487 "duala.y"
                     {
        /* Handle step value */
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    pop eax\n");  /* step value */
        fprintf(fichier_asm, "    mov [pas_pour_%d], eax\n", etiq);
    }
#line 1864 "duala.tab.c"
    break;

  case 68: /* boucle_pour_init: POUR IDENTIFICATEUR DE expression A expression  */
#line 495 "duala.y"
                                                   {
        char *var = current_id;
        etiquette_counter++;
        int etiq = etiquette_counter;
        etiquette_stack[stack_ptr++] = etiq;
        
        // Track this for loop limit variable
        for_limit_labels[for_limit_count++] = etiq;
        
        fprintf(fichier_asm, "    ; Initialisation de la boucle POUR %s\n", var);
        
        // Get the start and limit values from the stack
        fprintf(fichier_asm, "    pop ebx\n");  // limit value
        fprintf(fichier_asm, "    pop eax\n");  // start value
        
        // Store the values
        fprintf(fichier_asm, "    mov [%s], eax      ; Valeur initiale de %s\n", var, var);
        fprintf(fichier_asm, "    mov [limite_pour_%d], ebx  ; Limite de la boucle\n", etiq);
        
        // Default step is 1 (will be overridden if PAS is specified)
        fprintf(fichier_asm, "    mov dword [pas_pour_%d], 1  ; Pas par défaut\n", etiq);
        
        // Start of the loop with condition check
        fprintf(fichier_asm, "debut_pour_%d:\n", etiq);
        
        // Check if we should continue the loop
        // Compare loop variable with limit (i <= limit)
        fprintf(fichier_asm, "    mov eax, [%s]\n", var);
        fprintf(fichier_asm, "    cmp eax, [limite_pour_%d]\n", etiq);
        fprintf(fichier_asm, "    jg fin_pour_%d  ; Si >, sortir de la boucle\n", etiq);
        
        printf("-> POUR %s (étiquette: %d)\n", var, etiq);
    }
#line 1902 "duala.tab.c"
    break;

  case 69: /* $@14: %empty  */
#line 531 "duala.y"
            {
        etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiquette_counter;
        int etiq = etiquette_counter;
        fprintf(fichier_asm, "debut_repeter_%d:\n", etiq);
        printf("🔄 SƆŊƆLƆ (do-while)\n");
    }
#line 1914 "duala.tab.c"
    break;

  case 70: /* boucle_repeter: REPETER $@14 instructions JUSQUA PAREN_OUV expression PAREN_FERM POINT_VIRGULE  */
#line 537 "duala.y"
                                                                        {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, 0\n");
        fprintf(fichier_asm, "    jne debut_repeter_%d\n", etiq);
        printf("🔚 TƐMBƐLƐ (condition)\n");
    }
#line 1926 "duala.tab.c"
    break;


#line 1930 "duala.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 546 "duala.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erreur de syntaxe: %s\n", s);
}

int main() {
    printf("=== Compilateur Duala ===\n");
    printf("Tɔlɛ programme na wo:\n");
    return yyparse();
}
