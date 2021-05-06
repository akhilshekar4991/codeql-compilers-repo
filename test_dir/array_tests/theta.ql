import cpp
import semmle.code.cpp.dataflow.DataFlow

predicate searchForIfStmt(BlockStmt b, ForStmt f) {
	exists(IfStmt i | 
		i.getParent() = b
	and	b.getParentStmt() =f)
}
predicate searchForsecondForStmt(BlockStmt b2, ForStmt f2) {
	exists(ForStmt f3 | 
		f3.getParent() = b2
	and	b2.getParentStmt() =f2)
}

predicate searchForForStmt(BlockStmt b, ForStmt f) {
	exists(ForStmt i | 
		i.getParent() = b
	and	b.getParentStmt() =f
	and	searchForsecondForStmt(i.getStmt(), i))
}

from ForStmt forst, BlockStmt Body_1_stmt
where	forst.getStmt() = Body_1_stmt 
//and	exists(IfStmt i |
//		i.getParent() = Body_1_stmt)
//	exists(ForStmt forst2 | 
and	searchForForStmt(Body_1_stmt, forst)
		
select forst.getLocation(), Body_1_stmt.getParent()
