import cpp
import semmle.code.cpp.dataflow.DataFlow

predicate searchForIfStmt(Block b, ForStmt f) {
	exists(IfStmt i | 
		i.getParent() = b
	and	b.getParentStmt() =f)
}

predicate searchForForStmt(Block b, ForStmt f) {
	exists(ForStmt i | 
		i.getParent() = b
	and	b.getParentStmt() =f)
}

from ForStmt forst, BlockStmt Body_1_stmt
where	forst.getStmt() = Body_1_stmt 
//and	exists(IfStmt i |
//		i.getParent() = Body_1_stmt)
//	exists(ForStmt forst2 | 
and	searchForForStmt(Body_1_stmt, forst)
		
select forst.getLocation(), Body_1_stmt.getParent()
