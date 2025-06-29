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
  YYSYMBOL_partie_sinon_opt = 67,          /* partie_sinon_opt  */
  YYSYMBOL_68_7 = 68,                      /* $@7  */
  YYSYMBOL_boucle_tant_que = 69,           /* boucle_tant_que  */
  YYSYMBOL_70_8 = 70,                      /* $@8  */
  YYSYMBOL_fin_boucle = 71,                /* fin_boucle  */
  YYSYMBOL_lecture = 72,                   /* lecture  */
  YYSYMBOL_ecriture = 73,                  /* ecriture  */
  YYSYMBOL_74_9 = 74,                      /* $@9  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_structure_selon = 76,           /* structure_selon  */
  YYSYMBOL_77_11 = 77,                     /* $@11  */
  YYSYMBOL_liste_cas = 78,                 /* liste_cas  */
  YYSYMBOL_cas_simple = 79,                /* cas_simple  */
  YYSYMBOL_80_12 = 80,                     /* $@12  */
  YYSYMBOL_partie_defaut_opt = 81,         /* partie_defaut_opt  */
  YYSYMBOL_82_13 = 82,                     /* $@13  */
  YYSYMBOL_sortir_instruction = 83,        /* sortir_instruction  */
  YYSYMBOL_boucle_pour = 84,               /* boucle_pour  */
  YYSYMBOL_pas_opt = 85,                   /* pas_opt  */
  YYSYMBOL_boucle_pour_init = 86,          /* boucle_pour_init  */
  YYSYMBOL_boucle_repeter = 87,            /* boucle_repeter  */
  YYSYMBOL_88_14 = 88                      /* $@14  */
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
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

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
       0,    48,    48,    48,   114,   114,   127,   129,   133,   139,
     141,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     157,   157,   168,   169,   173,   174,   174,   181,   191,   191,
     200,   209,   221,   222,   229,   237,   248,   253,   258,   274,
     281,   281,   297,   299,   299,   310,   310,   323,   330,   340,
     354,   357,   354,   378,   378,   392,   393,   397,   397,   413,
     415,   415,   422,   430,   442,   446,   454,   483,   483
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
  "conditionnelle", "$@6", "partie_sinon_opt", "$@7", "boucle_tant_que",
  "$@8", "fin_boucle", "lecture", "ecriture", "$@9", "$@10",
  "structure_selon", "$@11", "liste_cas", "cas_simple", "$@12",
  "partie_defaut_opt", "$@13", "sortir_instruction", "boucle_pour",
  "pas_opt", "boucle_pour_init", "boucle_repeter", "$@14", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,   -42,    20,   -42,   -42,     8,    17,   -42,   -21,   -42,
     -42,    -4,   100,   -42,    10,   -42,    16,    21,    25,    39,
      43,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,    47,   -42,    50,   -30,   -30,   -30,   -30,   -42,
      69,   -42,    65,   -30,    82,   -42,   -30,   -42,   -42,   -42,
     -42,   -26,   -42,     6,   -42,    54,    55,    58,   -30,    11,
     -30,   -42,   -42,    59,    64,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,    96,    97,   -42,    87,    70,    74,    26,
     -42,   -42,    -6,    -6,    -6,     6,     6,   -42,   -42,   -42,
     -42,   -42,    98,   -30,   -30,   -42,   -42,   -42,   -42,   -42,
     -42,   -30,    23,   -42,   -42,    75,    57,    79,    73,    83,
     -42,   110,    90,   -42,   107,    92,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   100,   115,   100,    93,
      31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     2,     0,     6,     1,     0,     4,     3,     0,     9,
       7,     0,     5,     8,     0,    50,     0,     0,     0,     0,
       0,    67,    20,    10,    11,    14,    17,    12,    13,    15,
      16,    18,    64,    19,     0,     0,     0,     0,     0,    62,
       0,     9,     0,     0,     0,    49,     0,    36,    37,    38,
      51,    22,    23,    24,    32,     0,     0,     0,     0,     0,
       0,    65,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
      39,    52,    31,    28,    30,    25,    27,    33,    34,    35,
      40,    45,     0,     0,     0,    21,    63,    29,    26,     9,
       9,     0,    59,    55,    66,     0,    42,     0,     0,     0,
      56,     0,     0,    43,     0,    47,    57,    60,    54,    68,
       9,    41,    48,    46,     9,     9,    44,     0,    61,     0,
      62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -41,   -42,   -42,
     -42,   -33,   -13,   -42,   -42,   -42,    12,     3,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,    34,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     5,     9,     6,    10,    12,    23,    24,
      42,    50,    51,    98,    52,    97,    53,    54,    25,    99,
     114,   120,    26,   100,   123,    27,    28,    35,    64,    29,
      92,   102,   103,   124,   111,   125,    30,    31,    44,    32,
      33,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,     1,    65,    55,    56,    57,    66,    67,    68,    69,
      61,    46,     7,    63,    47,    48,    49,    14,    15,    16,
       4,    79,     8,    17,    11,    76,    18,    78,    68,    69,
      19,    20,    14,    15,    16,    13,    21,    77,    17,   101,
     109,    18,    70,    71,    72,    19,    20,   -58,   -58,   -58,
      96,    21,    82,    83,    84,    34,    22,    36,   106,   107,
     104,   105,    37,    14,    15,    16,    38,   113,   108,    17,
      43,    22,    18,    87,    88,    89,    19,    20,    39,   126,
      85,    86,    21,   127,   128,    14,    15,    16,    40,    45,
      58,    17,    60,   115,    18,    62,    73,    74,    19,    20,
      75,    80,    22,    81,    21,    90,    14,    15,    16,    93,
      91,    94,    17,    95,   101,    18,   116,   112,   121,    19,
      20,    14,    15,    16,    22,    21,   117,    17,   118,   119,
      18,   122,   130,     0,   129,    20,   110,     0,     0,     0,
      21,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22
};

static const yytype_int8 yycheck[] =
{
      41,     3,    28,    36,    37,    38,    32,    33,    34,    35,
      43,    41,     4,    46,    44,    45,    46,     6,     7,     8,
       0,    62,     5,    12,    45,    58,    15,    60,    34,    35,
      19,    20,     6,     7,     8,    39,    25,    26,    12,    16,
      17,    15,    36,    37,    38,    19,    20,    16,    17,    18,
      24,    25,    65,    66,    67,    45,    45,    41,    99,   100,
      93,    94,    41,     6,     7,     8,    41,    10,   101,    12,
      23,    45,    15,    70,    71,    72,    19,    20,    39,   120,
      68,    69,    25,   124,   125,     6,     7,     8,    45,    39,
      21,    12,    27,    14,    15,    13,    42,    42,    19,    20,
      42,    42,    45,    39,    25,     9,     6,     7,     8,    22,
      13,    41,    12,    39,    16,    15,    43,    42,    11,    19,
      20,     6,     7,     8,    45,    25,    43,    12,    18,    39,
      15,    39,    39,    -1,    19,    20,   102,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    48,    49,     0,    50,    52,     4,     5,    51,
      53,    45,    54,    39,     6,     7,     8,    12,    15,    19,
      20,    25,    45,    55,    56,    65,    69,    72,    73,    76,
      83,    84,    86,    87,    45,    74,    41,    41,    41,    39,
      45,    88,    57,    23,    85,    39,    41,    44,    45,    46,
      58,    59,    61,    63,    64,    58,    58,    58,    21,    54,
      27,    58,    13,    58,    75,    28,    32,    33,    34,    35,
      36,    37,    38,    42,    42,    42,    58,    26,    58,    54,
      42,    39,    59,    59,    59,    63,    63,    64,    64,    64,
       9,    13,    77,    22,    41,    39,    24,    62,    60,    66,
      70,    16,    78,    79,    58,    58,    54,    54,    58,    17,
      79,    81,    42,    10,    67,    14,    43,    43,    18,    39,
      68,    11,    39,    71,    80,    82,    54,    54,    54,    19,
      39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    49,    48,    51,    50,    52,    52,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      57,    56,    58,    58,    59,    60,    59,    59,    62,    61,
      61,    61,    63,    63,    63,    63,    64,    64,    64,    64,
      66,    65,    67,    68,    67,    70,    69,    71,    71,    72,
      74,    75,    73,    77,    76,    78,    78,    80,    79,    81,
      82,    81,    83,    84,    85,    85,    86,    88,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     3,     0,     2,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     1,     1,     1,     0,     4,     3,     0,     4,
       3,     3,     1,     3,     3,     3,     1,     1,     1,     3,
       0,     9,     0,     0,     3,     0,     9,     0,     1,     3,
       0,     0,     5,     0,     8,     1,     2,     0,     7,     0,
       0,     4,     2,     5,     0,     2,     6,     0,     8
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
#line 1286 "duala.tab.c"
    break;

  case 3: /* programme: DEBUT $@1 bloc FIN  */
#line 59 "duala.y"
        { 
        fprintf(fichier_asm, "    ret\n");
        
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
#line 1343 "duala.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 114 "duala.y"
                 { 
        fprintf(fichier_asm, "\nsection .text\n");
        fprintf(fichier_asm, "    global _start\n");
        fprintf(fichier_asm, "    extern printf, scanf\n");
        fprintf(fichier_asm, "_start:\n");
        fprintf(fichier_asm, "    call main\n");
        fprintf(fichier_asm, "    mov eax, 1\n");
        fprintf(fichier_asm, "    mov ebx, 0\n");
        fprintf(fichier_asm, "    int 0x80\n");
        fprintf(fichier_asm, "main:\n");
    }
#line 1359 "duala.tab.c"
    break;

  case 8: /* declaration: TYPE_ENTIER IDENTIFICATEUR POINT_VIRGULE  */
#line 133 "duala.y"
                                             {
        fprintf(fichier_asm, "    %s dd 0\n", current_id);
        printf("Variable declaree: %s\n", current_id);
    }
#line 1368 "duala.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 157 "duala.y"
                   {
        strcpy(affectation_var, current_id);
    }
#line 1376 "duala.tab.c"
    break;

  case 21: /* affectation: IDENTIFICATEUR $@3 AFFECTATION expression POINT_VIRGULE  */
#line 159 "duala.y"
                                           {
        fprintf(fichier_asm, "    ; Affectation a %s\n", affectation_var);
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    mov [%s], eax\n", affectation_var);
        printf("Affectation a: %s\n", affectation_var);
    }
#line 1387 "duala.tab.c"
    break;

  case 22: /* expression: expression_arith  */
#line 168 "duala.y"
                     { printf("PARSER: expression -> expression_arith\n"); }
#line 1393 "duala.tab.c"
    break;

  case 23: /* expression: expression_comp  */
#line 169 "duala.y"
                      { printf("PARSER: expression -> expression_comp\n"); }
#line 1399 "duala.tab.c"
    break;

  case 24: /* expression_arith: terme  */
#line 173 "duala.y"
          { printf("PARSER: expression_arith -> terme\n"); }
#line 1405 "duala.tab.c"
    break;

  case 25: /* $@4: %empty  */
#line 174 "duala.y"
                                  { printf("PARSER: expression_arith -> expression_arith PLUS terme\n"); }
#line 1411 "duala.tab.c"
    break;

  case 26: /* expression_arith: expression_arith PLUS terme $@4  */
#line 174 "duala.y"
                                                                                                           {
        fprintf(fichier_asm, "    ; Addition\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    add eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1423 "duala.tab.c"
    break;

  case 27: /* expression_arith: expression_arith MOINS terme  */
#line 181 "duala.y"
                                   {
        fprintf(fichier_asm, "    ; Soustraction\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    sub eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1435 "duala.tab.c"
    break;

  case 28: /* $@5: %empty  */
#line 191 "duala.y"
                                                { printf("PARSER: expression_comp -> expression_arith SUPERIEUR expression_arith\n"); }
#line 1441 "duala.tab.c"
    break;

  case 29: /* expression_comp: expression_arith SUPERIEUR expression_arith $@5  */
#line 191 "duala.y"
                                                                                                                                        {
        fprintf(fichier_asm, "    ; Comparaison >\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setg al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1455 "duala.tab.c"
    break;

  case 30: /* expression_comp: expression_arith INFERIEUR expression_arith  */
#line 200 "duala.y"
                                                  {
        fprintf(fichier_asm, "    ; Comparaison <\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setl al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1469 "duala.tab.c"
    break;

  case 31: /* expression_comp: expression_arith EGAL expression_arith  */
#line 209 "duala.y"
                                             {
        fprintf(fichier_asm, "    ; Comparaison ==\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    sete al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1483 "duala.tab.c"
    break;

  case 33: /* terme: terme FOIS facteur  */
#line 222 "duala.y"
                         {
        fprintf(fichier_asm, "    ; Multiplication\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    imul eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1495 "duala.tab.c"
    break;

  case 34: /* terme: terme DIVISE facteur  */
#line 229 "duala.y"
                           {
        fprintf(fichier_asm, "    ; Division\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1508 "duala.tab.c"
    break;

  case 35: /* terme: terme MODULO facteur  */
#line 237 "duala.y"
                           {
        fprintf(fichier_asm, "    ; Modulo\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push edx\n");
    }
#line 1521 "duala.tab.c"
    break;

  case 36: /* facteur: NOMBRE_ENTIER  */
#line 248 "duala.y"
                  {
        fprintf(fichier_asm, "    ; Constante %d\n", yylval);
        fprintf(fichier_asm, "    push %d\n", yylval);
        printf("Constante: %d\n", yylval);
    }
#line 1531 "duala.tab.c"
    break;

  case 37: /* facteur: IDENTIFICATEUR  */
#line 253 "duala.y"
                     {
        fprintf(fichier_asm, "    ; Variable %s\n", current_id);
        fprintf(fichier_asm, "    push dword [%s]\n", current_id);
        printf("Variable utilisee: %s\n", current_id);
    }
#line 1541 "duala.tab.c"
    break;

  case 38: /* facteur: STRING_LITERAL  */
#line 258 "duala.y"
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
#line 1562 "duala.tab.c"
    break;

  case 39: /* facteur: PAREN_OUV expression PAREN_FERM  */
#line 274 "duala.y"
                                      {
        /* Parenthesized expression - nothing extra to do */
        printf("Expression parenthesee\n");
    }
#line 1571 "duala.tab.c"
    break;

  case 40: /* $@6: %empty  */
#line 281 "duala.y"
                                             {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "    ; Debut SI\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz fin_si_%d\n", etiq);
        printf("Mbɔmbɔ condition SƆ\n");
    }
#line 1585 "duala.tab.c"
    break;

  case 41: /* conditionnelle: SI PAREN_OUV expression PAREN_FERM ALORS $@6 instructions partie_sinon_opt FINSI  */
#line 289 "duala.y"
                                          {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_si_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin SI\n");
        printf("Suka condition SƆ\n");
    }
#line 1596 "duala.tab.c"
    break;

  case 43: /* $@7: %empty  */
#line 299 "duala.y"
            {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_si_%d\n", etiq);
        fprintf(fichier_asm, "sinon_%d:\n", etiq);
        printf("Partie KƐMA\n");
    }
#line 1607 "duala.tab.c"
    break;

  case 44: /* partie_sinon_opt: SINON $@7 instructions  */
#line 304 "duala.y"
                   {
        // La partie sinon est terminée, on va vers fin_si
    }
#line 1615 "duala.tab.c"
    break;

  case 45: /* $@8: %empty  */
#line 310 "duala.y"
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
#line 1630 "duala.tab.c"
    break;

  case 47: /* fin_boucle: %empty  */
#line 323 "duala.y"
                {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    jmp debut_boucle_%d\n", etiq);
        fprintf(fichier_asm, "fin_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin MBELE\n");
        printf("Suka boucle MBELE\n");
    }
#line 1642 "duala.tab.c"
    break;

  case 48: /* fin_boucle: POINT_VIRGULE  */
#line 330 "duala.y"
                    {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    jmp debut_boucle_%d\n", etiq);
        fprintf(fichier_asm, "fin_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin MBELE\n");
        printf("Suka boucle MBELE (with semicolon)\n");
    }
#line 1654 "duala.tab.c"
    break;

  case 49: /* lecture: LIRE IDENTIFICATEUR POINT_VIRGULE  */
#line 340 "duala.y"
                                      {
        fprintf(fichier_asm, "    ; Lecture de %s\n", current_id);
        fprintf(fichier_asm, "    push input_msg\n");
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 4\n");
        fprintf(fichier_asm, "    push %s\n", current_id);
        fprintf(fichier_asm, "    push input_format\n");
        fprintf(fichier_asm, "    call scanf\n");
        fprintf(fichier_asm, "    add esp, 8\n");
        printf("Yɛnɛ: %s\n", current_id);
    }
#line 1670 "duala.tab.c"
    break;

  case 50: /* $@9: %empty  */
#line 354 "duala.y"
           { 
        printf("PARSER: [ECRIRE] Start of ECRIRE statement at line %d\n", yylineno);
        printf("PARSER: [ECRIRE] Current token: %d\n", yychar);
    }
#line 1679 "duala.tab.c"
    break;

  case 51: /* $@10: %empty  */
#line 357 "duala.y"
                 { 
        printf("PARSER: [ECRIRE] Successfully parsed expression\n");
        printf("PARSER: [ECRIRE] Next token (expecting POINT_VIRGULE): %d\n", yychar);
    }
#line 1688 "duala.tab.c"
    break;

  case 52: /* ecriture: ECRIRE $@9 expression $@10 POINT_VIRGULE  */
#line 360 "duala.y"
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
        fprintf(fichier_asm, "    add esp, 8\n");
        printf("Kɔma expression\n");
    }
#line 1708 "duala.tab.c"
    break;

  case 53: /* $@11: %empty  */
#line 378 "duala.y"
                                          {
        fprintf(fichier_asm, "    ; NDƆŊ (switch)\n");
        fprintf(fichier_asm, "    pop eax\n");
        etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiquette_counter;
        printf("🔀 NDƆŊ (switch)\n");
    }
#line 1720 "duala.tab.c"
    break;

  case 54: /* structure_selon: SELON PAREN_OUV expression PAREN_FERM $@11 liste_cas partie_defaut_opt FINSELON  */
#line 384 "duala.y"
                                           {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_selon_%d:\n", etiq);
        printf("🔚 Suka NDƆŊ\n");
    }
#line 1730 "duala.tab.c"
    break;

  case 57: /* $@12: %empty  */
#line 397 "duala.y"
                               {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    ; Cas\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        etiquette_counter++;
        fprintf(fichier_asm, "    jne cas_suivant_%d\n", etiquette_counter);
        printf("📋 KƐS\n");
    }
#line 1744 "duala.tab.c"
    break;

  case 58: /* cas_simple: CAS expression DEUX_POINTS $@12 instructions SORTIR POINT_VIRGULE  */
#line 405 "duala.y"
                                        {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq);
        fprintf(fichier_asm, "cas_suivant_%d:\n", etiquette_counter);
        printf("🙪 BIMA (break)\n");
    }
#line 1755 "duala.tab.c"
    break;

  case 60: /* $@13: %empty  */
#line 415 "duala.y"
                         {
        fprintf(fichier_asm, "    ; CAS DEFAUT\n");
        printf("📋 KƐS BƆSƆ\n");
    }
#line 1764 "duala.tab.c"
    break;

  case 62: /* sortir_instruction: SORTIR POINT_VIRGULE  */
#line 422 "duala.y"
                         {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq);
        printf("🚪 BIMA (break)\n");
    }
#line 1774 "duala.tab.c"
    break;

  case 63: /* boucle_pour: boucle_pour_init pas_opt SALA instructions FINPOUR  */
#line 430 "duala.y"
                                                       {
        int etiq = etiquette_stack[--stack_ptr];
        char *var = current_id;
        /* Use the step value */
        fprintf(fichier_asm, "    mov eax, [pas_pour_%d]\n", etiq);
        fprintf(fichier_asm, "    add [%s], eax\n", var);
        fprintf(fichier_asm, "    jmp debut_pour_%d\n", etiq);
        fprintf(fichier_asm, "fin_pour_%d:\n", etiq);
        printf("<- Fin POUR\n");
    }
#line 1789 "duala.tab.c"
    break;

  case 64: /* pas_opt: %empty  */
#line 442 "duala.y"
                                        {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    ; Using default step of 1\n");
    }
#line 1798 "duala.tab.c"
    break;

  case 65: /* pas_opt: PAS expression  */
#line 446 "duala.y"
                     {
        /* Handle step value */
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    pop eax\n");  /* step value */
        fprintf(fichier_asm, "    mov [pas_pour_%d], eax\n", etiq);
    }
#line 1809 "duala.tab.c"
    break;

  case 66: /* boucle_pour_init: POUR IDENTIFICATEUR DE expression A expression  */
#line 454 "duala.y"
                                                   {
        char *var = current_id;
        etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiquette_counter;
        int etiq = etiquette_counter;
        
        /* Track this for loop limit variable */
        for_limit_labels[for_limit_count++] = etiq;
        
        fprintf(fichier_asm, "    ; POUR %s\n", var);
        
        /* Store the limit value */
        fprintf(fichier_asm, "    pop ebx\n");  /* limit */
        fprintf(fichier_asm, "    pop eax\n");  /* start value */
        fprintf(fichier_asm, "    mov [%s], eax\n", var);
        fprintf(fichier_asm, "    mov [limite_pour_%d], ebx\n", etiq);
        /* Default step is 1 */
        fprintf(fichier_asm, "    mov dword [pas_pour_%d], 1\n", etiq);
        
        fprintf(fichier_asm, "debut_pour_%d:\n", etiq);
        fprintf(fichier_asm, "    mov eax, [%s]\n", var);
        fprintf(fichier_asm, "    cmp eax, [limite_pour_%d]\n", etiq);
        /* Check if we've passed the limit (handles both incrementing and decrementing) */
        fprintf(fichier_asm, "    jg fin_pour_%d\n", etiq);
        printf("-> POUR %s\n", var);
    }
#line 1840 "duala.tab.c"
    break;

  case 67: /* $@14: %empty  */
#line 483 "duala.y"
            {
        etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiquette_counter;
        int etiq = etiquette_counter;
        fprintf(fichier_asm, "debut_repeter_%d:\n", etiq);
        printf("🔄 SƆŊƆLƆ (do-while)\n");
    }
#line 1852 "duala.tab.c"
    break;

  case 68: /* boucle_repeter: REPETER $@14 instructions JUSQUA PAREN_OUV expression PAREN_FERM POINT_VIRGULE  */
#line 489 "duala.y"
                                                                        {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, 0\n");
        fprintf(fichier_asm, "    jne debut_repeter_%d\n", etiq);
        printf("🔚 TƐMBƐLƐ (condition)\n");
    }
#line 1864 "duala.tab.c"
    break;


#line 1868 "duala.tab.c"

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

#line 498 "duala.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erreur de syntaxe: %s\n", s);
}

int main() {
    printf("=== Compilateur Duala ===\n");
    printf("Tɔlɛ programme na wo:\n");
    return yyparse();
}
