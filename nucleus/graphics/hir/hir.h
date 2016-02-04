/**
 * (c) 2014-2016 Alexandro Sanchez Bach. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#pragma once

#include "nucleus/common.h"

namespace gfx {
namespace hir {

/**
 * High-level Intermediate Representation
 * ======================================
 * Since the Vulkan backend has priority over backends and its shading and computing
 * intermediate representation is flexible and powerful enough for all current goals,
 * this HIR mimics a subset of SPIR-V. This could however change in the future.
 *
 * References:
 *  - SPIR-V Specification. Version 1.00, Revision 2. November 14, 2015.
 */

using Literal = U32;

enum StorageClass {
    UNIFORM_CONSTANT = 0,
    INPUT = 1,
    OUTPUT = 3,
    FUNCTION = 7,
};

enum Dimension {
    DIMENSION_1D = 0,
    DIMENSION_2D = 1,
    DIMENSION_3D = 2,
};

enum Decoration {
    DECORATION_BLOCK = 2,
    DECORATION_BUILTIN = 11,
    DECORATION_LOCATION = 30,
    DECORATION_BINDING = 33,
};

enum BuiltIn {
    BUILTIN_POSITION = 0,
    BUILTIN_POINTSIZE = 1,
    BUILTIN_CLIPDISTANCE = 3,
    BUILTIN_CULLDISTANCE = 4,
    BUILTIN_VERTEXID = 5,
    BUILTIN_INSTANCEID = 6,
    BUILTIN_PRIMITIVEID = 7,
    BUILTIN_INVOCATIONID = 8,
    BUILTIN_LAYER = 9,
    BUILTIN_VIEWPORTINDEX = 10,
    BUILTIN_TESSLEVELOUTER = 11,
    BUILTIN_TESSLEVELINNER = 12,
    BUILTIN_TESSCOORD = 13,
    BUILTIN_PATCHVERTICES = 14,
    BUILTIN_FRAGCOORD = 15,
    BUILTIN_POINTCOORD = 16,
    BUILTIN_FRONTFACING = 17,
    BUILTIN_SAMPLEID = 18,
    BUILTIN_SAMPLEPOSITION = 19,
    BUILTIN_SAMPLEMASK = 20,
    BUILTIN_FRAGDEPTH = 22,
    BUILTIN_HELPERINVOCATION = 23,
    BUILTIN_NUMWORKGROUPS = 24,
    BUILTIN_WORKGROUPSIZE = 25,
    BUILTIN_WORKGROUPID = 26,
    BUILTIN_LOCALINVOCATIONID = 27,
    BUILTIN_GLOBALINVOCATIONID = 28,
    BUILTIN_LOCALINVOCATIONINDEX = 29,
    BUILTIN_WORKDIM = 30,
    BUILTIN_GLOBALSIZE = 31,
    BUILTIN_ENQUEUEDWORKGROUPSIZE = 32,
    BUILTIN_GLOBALOFFSET = 33,
    BUILTIN_GLOBALLINEARID = 34,
    BUILTIN_SUBGROUPSIZE = 36,
    BUILTIN_SUBGROUPMAXSIZE = 37,
    BUILTIN_NUMSUBGROUPS = 38,
    BUILTIN_NUMENQUEUEDSUBGROUPS = 39,
    BUILTIN_SUBGROUPID = 40,
    BUILTIN_SUBGROUPLOCALINVOCATIONID = 41,
    BUILTIN_VERTEXINDEX = 42,
    BUILTIN_INSTANCEINDEX = 43,
};

enum Opcode {
    OP_NOP = 0,
    OP_UNDEF = 1,
    OP_SOURCE_CONTINUED = 2,
    OP_SOURCE = 3,
    OP_SOURCE_EXTENSION = 4,
    OP_NAME = 5,
    OP_MEMBER_NAME = 6,
    OP_STRING = 7,
    OP_LINE = 8,
    OP_EXTENSION = 10,
    OP_EXT_INST_IMPORT = 11,
    OP_EXT_INST = 12,
    OP_MEMORY_MODEL = 14,
    OP_ENTRY_POINT = 15,
    OP_EXECUTION_MODE = 16,
    OP_CAPABILITY = 17,
    OP_TYPE_VOID = 19,
    OP_TYPE_BOOL = 20,
    OP_TYPE_INT = 21,
    OP_TYPE_FLOAT = 22,
    OP_TYPE_VECTOR = 23,
    OP_TYPE_MATRIX = 24,
    OP_TYPE_IMAGE = 25,
    OP_TYPE_SAMPLER = 26,
    OP_TYPE_SAMPLED_IMAGE = 27,
    OP_TYPE_ARRAY = 28,
    OP_TYPE_RUNTIME_ARRAY = 29,
    OP_TYPE_STRUCT = 30,
    OP_TYPE_OPAQUE = 31,
    OP_TYPE_POINTER = 32,
    OP_TYPE_FUNCTION = 33,
    OP_TYPE_EVENT = 34,
    OP_TYPE_DEVICE_EVENT = 35,
    OP_TYPE_RESERVE_ID = 36,
    OP_TYPE_QUEUE = 37,
    OP_TYPE_PIPE = 38,
    OP_TYPE_FORWARD_POINTER = 39,
    OP_CONSTANT_TRUE = 41,
    OP_CONSTANT_FALSE = 42,
    OP_CONSTANT = 43,
    OP_CONSTANT_COMPOSITE = 44,
    OP_CONSTANT_SAMPLER = 45,
    OP_CONSTANT_NULL = 46,
    OP_SPEC_CONSTANT_TRUE = 48,
    OP_SPEC_CONSTANT_FALSE = 49,
    OP_SPEC_CONSTANT = 50,
    OP_SPEC_CONSTANT_COMPOSITE = 51,
    OP_SPEC_CONSTANT_OP = 52,
    OP_FUNCTION = 54,
    OP_FUNCTION_PARAMETER = 55,
    OP_FUNCTION_END = 56,
    OP_FUNCTION_CALL = 57,
    OP_VARIABLE = 59,
    OP_IMAGE_TEXEL_POINTER = 60,
    OP_LOAD = 61,
    OP_STORE = 62,
    OP_COPY_MEMORY = 63,
    OP_COPY_MEMORY_SIZED = 64,
    OP_ACCESS_CHAIN = 65,
    OP_IN_BOUNDS_ACCESS_CHAIN = 66,
    OP_PTR_ACCESS_CHAIN = 67,
    OP_ARRAY_LENGTH = 68,
    OP_GENERIC_PTR_MEM_SEMANTICS = 69,
    OP_IN_BOUNDS_PTR_ACCESS_CHAIN = 70,
    OP_DECORATE = 71,
    OP_MEMBER_DECORATE = 72,
    OP_DECORATION_GROUP = 73,
    OP_GROUP_DECORATE = 74,
    OP_GROUP_MEMBER_DECORATE = 75,
    OP_VECTOR_EXTRACT_DYNAMIC = 77,
    OP_VECTOR_INSERT_DYNAMIC = 78,
    OP_VECTOR_SHUFFLE = 79,
    OP_COMPOSITE_CONSTRUCT = 80,
    OP_COMPOSITE_EXTRACT = 81,
    OP_COMPOSITE_INSERT = 82,
    OP_COPY_OBJECT = 83,
    OP_TRANSPOSE = 84,
    OP_SAMPLED_IMAGE = 86,
    OP_IMAGE_SAMPLE_IMPLICIT_LOD = 87,
    OP_IMAGE_SAMPLE_EXPLICIT_LOD = 88,
    OP_IMAGE_SAMPLE_DREF_IMPLICIT_LOD = 89,
    OP_IMAGE_SAMPLE_DREF_EXPLICIT_LOD = 90,
    OP_IMAGE_SAMPLE_PROJ_IMPLICIT_LOD = 91,
    OP_IMAGE_SAMPLE_PROJ_EXPLICIT_LOD = 92,
    OP_IMAGE_SAMPLE_PROJ_DREF_IMPLICIT_LOD = 93,
    OP_IMAGE_SAMPLE_PROJ_DREF_EXPLICIT_LOD = 94,
    OP_IMAGE_FETCH = 95,
    OP_IMAGE_GATHER = 96,
    OP_IMAGE_DREF_GATHER = 97,
    OP_IMAGE_READ = 98,
    OP_IMAGE_WRITE = 99,
    OP_IMAGE = 100,
    OP_IMAGE_QUERY_FORMAT = 101,
    OP_IMAGE_QUERY_ORDER = 102,
    OP_IMAGE_QUERY_SIZE_LOD = 103,
    OP_IMAGE_QUERY_SIZE = 104,
    OP_IMAGE_QUERY_LOD = 105,
    OP_IMAGE_QUERY_LEVELS = 106,
    OP_IMAGE_QUERY_SAMPLES = 107,
    OP_CONVERT_F_TO_U = 109,
    OP_CONVERT_F_TO_S = 110,
    OP_CONVERT_S_TO_F = 111,
    OP_CONVERT_U_TO_F = 112,
    OP_UCONVERT = 113,
    OP_SCONVERT = 114,
    OP_FCONVERT = 115,
    OP_QUANTIZE_TO_F16 = 116,
    OP_CONVERT_PTR_TO_U = 117,
    OP_SAT_CONVERT_S_TO_U = 118,
    OP_SAT_CONVERT_U_TO_S = 119,
    OP_CONVERT_U_TO_PTR = 120,
    OP_PTR_CAST_TO_GENERIC = 121,
    OP_GENERIC_CAST_TO_PTR = 122,
    OP_GENERIC_CAST_TO_PTR_EXPLICIT = 123,
    OP_BITCAST = 124,
    OP_SNEGATE = 126,
    OP_FNEGATE = 127,
    OP_IADD = 128,
    OP_FADD = 129,
    OP_ISUB = 130,
    OP_FSUB = 131,
    OP_IMUL = 132,
    OP_FMUL = 133,
    OP_UDIV = 134,
    OP_SDIV = 135,
    OP_FDIV = 136,
    OP_UMOD = 137,
    OP_SREM = 138,
    OP_SMOD = 139,
    OP_FREM = 140,
    OP_FMOD = 141,
    OP_VECTOR_TIMES_SCALAR = 142,
    OP_MATRIX_TIMES_SCALAR = 143,
    OP_VECTOR_TIMES_MATRIX = 144,
    OP_MATRIX_TIMES_VECTOR = 145,
    OP_MATRIX_TIMES_MATRIX = 146,
    OP_OUTER_PRODUCT = 147,
    OP_DOT = 148,
    OP_IADD_CARRY = 149,
    OP_ISUB_BORROW = 150,
    OP_UMUL_EXTENDED = 151,
    OP_SMUL_EXTENDED = 152,
    OP_ANY = 154,
    OP_ALL = 155,
    OP_IS_NAN = 156,
    OP_IS_INF = 157,
    OP_IS_FINITE = 158,
    OP_IS_NORMAL = 159,
    OP_SIGN_BIT_SET = 160,
    OP_LESS_OR_GREATER = 161,
    OP_ORDERED = 162,
    OP_UNORDERED = 163,
    OP_LOGICAL_EQUAL = 164,
    OP_LOGICAL_NOT_EQUAL = 165,
    OP_LOGICAL_OR = 166,
    OP_LOGICAL_AND = 167,
    OP_LOGICAL_NOT = 168,
    OP_SELECT = 169,
    OP_IEQUAL = 170,
    OP_INOT_EQUAL = 171,
    OP_UGREATER_THAN = 172,
    OP_SGREATER_THAN = 173,
    OP_UGREATER_THAN_EQUAL = 174,
    OP_SGREATER_THAN_EQUAL = 175,
    OP_ULESS_THAN = 176,
    OP_SLESS_THAN = 177,
    OP_ULESS_THAN_EQUAL = 178,
    OP_SLESS_THAN_EQUAL = 179,
    OP_FORD_EQUAL = 180,
    OP_FUNORD_EQUAL = 181,
    OP_FORD_NOT_EQUAL = 182,
    OP_FUNORD_NOT_EQUAL = 183,
    OP_FORD_LESS_THAN = 184,
    OP_FUNORD_LESS_THAN = 185,
    OP_FORD_GREATER_THAN = 186,
    OP_FUNORD_GREATER_THAN = 187,
    OP_FORD_LESS_THAN_EQUAL = 188,
    OP_FUNORD_LESS_THAN_EQUAL = 189,
    OP_FORD_GREATER_THAN_EQUAL = 190,
    OP_FUNORD_GREATER_THAN_EQUAL = 191,
    OP_SHIFT_RIGHT_LOGICAL = 194,
    OP_SHIFT_RIGHT_ARITHMETIC = 195,
    OP_SHIFT_LEFT_LOGICAL = 196,
    OP_BITWISE_OR = 197,
    OP_BITWISE_XOR = 198,
    OP_BITWISE_AND = 199,
    OP_NOT = 200,
    OP_BIT_FIELD_INSERT = 201,
    OP_BIT_FIELD_S_EXTRACT = 202,
    OP_BIT_FIELD_U_EXTRACT = 203,
    OP_BIT_REVERSE = 204,
    OP_BIT_COUNT = 205,
    OP_DP_DX = 207,
    OP_DP_DY = 208,
    OP_FWIDTH = 209,
    OP_DP_DX_FINE = 210,
    OP_DP_DY_FINE = 211,
    OP_FWIDTH_FINE = 212,
    OP_DP_DX_COARSE = 213,
    OP_DP_DY_COARSE = 214,
    OP_FWIDTH_COARSE = 215,
    OP_EMIT_VERTEX = 218,
    OP_END_PRIMITIVE = 219,
    OP_EMIT_STREAM_VERTEX = 220,
    OP_END_STREAM_PRIMITIVE = 221,
    OP_CONTROL_BARRIER = 224,
    OP_MEMORY_BARRIER = 225,
    OP_ATOMIC_LOAD = 227,
    OP_ATOMIC_STORE = 228,
    OP_ATOMIC_EXCHANGE = 229,
    OP_ATOMIC_COMPARE_EXCHANGE = 230,
    OP_ATOMIC_COMPARE_EXCHANGE_WEAK = 231,
    OP_ATOMIC_I_INCREMENT = 232,
    OP_ATOMIC_I_DECREMENT = 233,
    OP_ATOMIC_I_ADD = 234,
    OP_ATOMIC_I_SUB = 235,
    OP_ATOMIC_S_MIN = 236,
    OP_ATOMIC_U_MIN = 237,
    OP_ATOMIC_S_MAX = 238,
    OP_ATOMIC_U_MAX = 239,
    OP_ATOMIC_AND = 240,
    OP_ATOMIC_OR = 241,
    OP_ATOMIC_XOR = 242,
    OP_PHI = 245,
    OP_LOOP_MERGE = 246,
    OP_SELECTION_MERGE = 247,
    OP_LABEL = 248,
    OP_BRANCH = 249,
    OP_BRANCH_CONDITIONAL = 250,
    OP_SWITCH = 251,
    OP_KILL = 252,
    OP_RETURN = 253,
    OP_RETURN_VALUE = 254,
    OP_UNREACHABLE = 255,
    OP_LIFETIME_START = 256,
    OP_LIFETIME_STOP = 257,
    OP_GROUP_ASYNC_COPY = 259,
    OP_GROUP_WAIT_EVENTS = 260,
    OP_GROUP_ALL = 261,
    OP_GROUP_ANY = 262,
    OP_GROUP_BROADCAST = 263,
    OP_GROUP_I_ADD = 264,
    OP_GROUP_F_ADD = 265,
    OP_GROUP_F_MIN = 266,
    OP_GROUP_U_MIN = 267,
    OP_GROUP_S_MIN = 268,
    OP_GROUP_F_MAX = 269,
    OP_GROUP_U_MAX = 270,
    OP_GROUP_S_MAX = 271,
    OP_READ_PIPE = 274,
    OP_WRITE_PIPE = 275,
    OP_RESERVED_READ_PIPE = 276,
    OP_RESERVED_WRITE_PIPE = 277,
    OP_RESERVE_READ_PIPE_PACKETS = 278,
    OP_RESERVE_WRITE_PIPE_PACKETS = 279,
    OP_COMMIT_READ_PIPE = 280,
    OP_COMMIT_WRITE_PIPE = 281,
    OP_IS_VALID_RESERVE_ID = 282,
    OP_GET_NUM_PIPE_PACKETS = 283,
    OP_GET_MAX_PIPE_PACKETS = 284,
    OP_GROUP_RESERVE_READ_PIPE_PACKETS = 285,
    OP_GROUP_RESERVE_WRITE_PIPE_PACKETS = 286,
    OP_GROUP_COMMIT_READ_PIPE = 287,
    OP_GROUP_COMMIT_WRITE_PIPE = 288,
    OP_ENQUEUE_MARKER = 291,
    OP_ENQUEUE_KERNEL = 292,
    OP_GET_KERNEL_N_DRANGE_SUB_GROUP_COUNT = 293,
    OP_GET_KERNEL_N_DRANGE_MAX_SUB_GROUP_SIZE = 294,
    OP_GET_KERNEL_WORK_GROUP_SIZE = 295,
    OP_GET_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE = 296,
    OP_RETAIN_EVENT = 297,
    OP_RELEASE_EVENT = 298,
    OP_CREATE_USER_EVENT = 299,
    OP_IS_VALID_EVENT = 300,
    OP_SET_USER_EVENT_STATUS = 301,
    OP_CAPTURE_EVENT_PROFILING_INFO = 302,
    OP_GET_DEFAULT_QUEUE = 303,
    OP_BUILD_N_D_RANGE = 304,
    OP_IMAGE_SPARSE_SAMPLE_IMPLICIT_LOD = 305,
    OP_IMAGE_SPARSE_SAMPLE_EXPLICIT_LOD = 306,
    OP_IMAGE_SPARSE_SAMPLE_DREF_IMPLICIT_LOD = 307,
    OP_IMAGE_SPARSE_SAMPLE_DREF_EXPLICIT_LOD = 308,
    OP_IMAGE_SPARSE_SAMPLE_PROJ_IMPLICIT_LOD = 309,
    OP_IMAGE_SPARSE_SAMPLE_PROJ_EXPLICIT_LOD = 310,
    OP_IMAGE_SPARSE_SAMPLE_PROJ_DREF_IMPLICIT_LOD = 311,
    OP_IMAGE_SPARSE_SAMPLE_PROJ_DREF_EXPLICIT_LOD = 312,
    OP_IMAGE_SPARSE_FETCH = 313,
    OP_IMAGE_SPARSE_GATHER = 314,
    OP_IMAGE_SPARSE_DREF_GATHER = 315,
    OP_IMAGE_SPARSE_TEXELS_RESIDENT = 316,
    OP_NO_LINE = 317,
    OP_ATOMIC_FLAG_TEST_AND_SET = 318,
    OP_ATOMIC_FLAG_CLEAR = 319,
};

}  // namespace hir
}  // namespace gfx
