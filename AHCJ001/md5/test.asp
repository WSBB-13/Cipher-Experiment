<body>
<!--#include file="md5.asp"-->
<%
AdminPWD=md5(trim(Request.Form("b")))
%>
<%=AdminPWD%>
</body>


