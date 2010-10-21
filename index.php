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
	die;
}

// Get existing lists and make option fields for them
$screen_name = getScreenName($connection);
$mylists = getListsByUser($screen_name, $connection);
$mylists_options;
foreach($mylists as $list)
{
	$mylists_options.="<option value='$list'>$list</option>\n";
}

function getListsByUser($username, &$connection)
{
	$result = $connection->get($username."/lists");
	$lists = array();
	foreach($result->lists as $list)
	{
		$lists[] = $list->slug;
	}
	return $lists;
}

function getScreenName(&$connection)
{
	$creds = $connection->get("account/verify_credentials");
	return $creds->screen_name;
}

/*$cursor = -1;
$content = $connection->get('account/rate_limit_status');

while($cursor)
{
	$results = $connection->get('Noleli/umsi/members', array("cursor"=>$cursor));	
	$members = array();
	
	foreach($results->users as $user)
	{
		$members[] = $user->screen_name;
	}
	$add_result = $connection->post('Noleli/test-list/members/create_all', array('screen_name'=>implode(",", $members)));
	$cursor = $results->next_cursor_str;
}*/

/* Include HTML to display on the page */
include('html.inc');
