$(document).ready(init);

function init()
{
	$("#source_user").focus();
	$("#get_source_lists").click(function() { getUserLists($("#source_user").val()) });
}

function getUserLists(username)
{
	var data = {action: "getUserLists", username: username};
	$.get('index.php', data, function(result) {
		//console.log(result);
		$("#source_list").empty();
		$.each($.parseJSON(result), function(i, v) {
			var opt = $("<option value='" + v + "'>" + v + "</option>");
			$("#source_list").append(opt);
		});
	});
}