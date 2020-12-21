#include <stdbool.h>
#define USE_STDBOOL 1

#include "postgres.h"
#include "pg_config.h"
#include "funcapi.h"
#include "miscadmin.h"
#include "pgstat.h"
#include "access/amapi.h"
#include "access/genam.h"
#include "access/heapam.h"
#include "access/htup.h"
#include "access/htup_details.h"
#include "access/reloptions.h"
#include "access/relscan.h"
#include "access/skey.h"
#include "access/sysattr.h"
#include "access/xact.h"

#define ScanKey struct ScanKeyData *
#include "nodes/execnodes.h"
#undef ScanKey

#include "catalog/index.h"
#include "catalog/namespace.h"
#include "catalog/pg_enum.h"
#include "catalog/pg_proc.h"
#include "catalog/pg_type.h"
#include "commands/comment.h"
#include "commands/dbcommands.h"
#include "commands/event_trigger.h"
#include "commands/proclang.h"
#include "catalog/dependency.h"
#include "catalog/objectaddress.h"
#include "catalog/pg_trigger.h"
#include "commands/tablecmds.h"
#include "commands/trigger.h"
#include "executor/executor.h"
#include "executor/spi.h"
#include "foreign/fdwapi.h"
#include "foreign/foreign.h"
#include "nodes/execnodes.h"
#include "nodes/extensible.h"
#include "nodes/makefuncs.h"
#include "nodes/nodeFuncs.h"
#include "nodes/nodes.h"
#include "nodes/print.h"
#include "nodes/relation.h"
#include "nodes/replnodes.h"
#include "nodes/tidbitmap.h"
#include "nodes/value.h"
#include "optimizer/cost.h"
#include "optimizer/clauses.h"
#include "optimizer/paths.h"
#include "optimizer/pathnode.h"
#include "optimizer/planner.h"
#include "optimizer/restrictinfo.h"
#include "parser/parse_func.h"
#include "parser/parse_type.h"
#include "parser/parser.h"
#include "postmaster/bgworker.h"
#include "rewrite/rewriteHandler.h"
#include "storage/block.h"
#include "storage/bufmgr.h"
#include "storage/lwlock.h"
#include "storage/procarray.h"
#include "storage/itemptr.h"
#include "storage/ipc.h"
#include "tcop/tcopprot.h"
#include "tcop/utility.h"
#include "utils/builtins.h"
#include "utils/date.h"
#define double float8
#include "utils/geo_decls.h"
#undef double
#include "utils/guc.h"
#include "utils/json.h"
#include "utils/jsonb.h"
#include "utils/syscache.h"
#include "utils/lsyscache.h"
#include "utils/memutils.h"
#include "utils/palloc.h"
#include "utils/rel.h"
#include "utils/relcache.h"
#include "utils/selfuncs.h"
#include "utils/snapmgr.h"
#include "utils/typcache.h"
