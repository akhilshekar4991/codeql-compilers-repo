import cpp
import semmle.code.cpp.dataflow.DataFlow
import semmle.code.cpp.Variable

from ForStmt forst, BlockStmt b
where 	forst.getStmt() = b
and	exists(MulExpr expr | 
		expr.getEnclosingBlock() = b)
and	exists(ArrayExpr a |
		a.getEnclosingBlock() = b)
select forst.getLocation(), "hello world 2"

//from ArrayExpr a
//select a.getEnclosingBlock().getLocation()
