<?php
/**
 * @file
 * User has successfully authenticated with Twitter. Access tokens saved to session and DB.
 */

/* Load required lib files. */
session_start();
require_once('twitteroauth/twitteroauth.php');
require_once('config.php');

/* If access tokens are not available redirect to connect page. */
if (empty($_SESSION['access_token']) || empty($_SESSION['access_token']['oauth_token']) || empty($_SESSION['access_token']['oauth_token_secret'])) {
    header('Location: ./clearsessions.php');
}
/* Get user access tokens out of the session. */
$access_token = $_SESSION['access_token'];

/* Create a TwitterOauth object with consumer/user tokens. */
$connection = new TwitterOAuth(CONSUMER_KEY, CONSUMER_SECRET, $access_token['oauth_token'], $access_token['oauth_token_secret']);

/* If method is set change API call made. Test is called by default. */
//$content = $connection->get('account/verify_credentials');

/* Some example calls */
//$content = $connection->get('users/show', array('screen_name' => 'noleli'));
//$content = $connection->post('statuses/update', array('status' => date(DATE_RFC822)));
//$connection->post('statuses/destroy', array('id' => 5437877770));
//$connection->post('friendships/create', array('id' => 9436992)));
//$connection->post('friendships/destroy', array('id' => 9436992)));

//$add_result = $connection->post('Noleli/test-list/members/create_all', array('screen_name'=>"noleli"));
//$add_result = $connection->get('Noleli/lists');
//$add_result = curl("http://api.twitter.com/1/noleli/test-list/create_all?screen_name=allspiritseve");
//25288421

if($_REQUEST["action"] == "getUserLists")
{
	//$result = $connection->get($_REQUEST["username"]."/lists");
	$lists = getListsByUser($_REQUEST["username"], $connection);
	echo json_encode($lists);
	// echo $lists;
	die;
}

// Get existing lists and make option fields for them
$screen_name = getScreenName($connection);
$mylists = getListsByUser($screen_name, $connection);
$mylists_options = "";
foreach($mylists as $list)
{
	$mylists_options.="<option value='{$list->slug}'>{$list->name}</option>\n";
}

function getListsByUser($username, &$connection)
{
	$result = $connection->get("lists/ownerships", array('screen_name' => $username, 'count' => 1000));
	$lists = array();
	$lists = $result->lists;
	return $lists;
}

function getScreenName(&$connection)
{
	$creds = $connection->get("account/verify_credentials");
	return $creds->screen_name;
}

if($_REQUEST["action"] == "copyLists")
{
	$cursor = -1;
	//$content = $connection->get('account/rate_limit_status');
	$total = 0;
	while($cursor)
	{
		// $results = $connection->get($_REQUEST["source_user"]."/".$_REQUEST["source_list"]."/members", array("cursor"=>$cursor));
		$results = $connection->get("lists/members", array("slug" => $_REQUEST["source_list"], "owner_screen_name" => $_REQUEST["source_user"], "include_entities" => "false", "skip_status" => "t", "cursor" => $cursor));
		$members = array();
		// echo json_encode($results);

		foreach($results->users as $user)
		{
			$members[] = $user->screen_name;
		}
		// echo json_encode($members);
		// $add_result = $connection->post(getScreenName($connection)."/".$_REQUEST["dest_list"].'/members/create_all', array('screen_name'=>implode(",", $members)));
		$add_result = $connection->post("lists/members/create_all", array("slug" => $_REQUEST["dest_list"], "owner_screen_name" => $screen_name, "screen_name" => implode(",", $members)));
		$cursor = $results->next_cursor_str;
		$total+=count($members);
	}
	$results = $connection->get("lists/show", array("slug" => $_REQUEST["dest_list"], "owner_screen_name" => $screen_name));
	echo "Added ".$total." people to ".$_REQUEST["dest_list"].", list now contains ".$results->member_count." members.";
	die;
}

/* Include HTML to display on the page */
include('html.inc');
