#include "pch.h"
#include "SRLNewsStoryGenerator.h"

vector<string> SRLNewsStoryGenerator::generateMinorPremiershipArticle(string teamName)
{
	vector<string> temp;
	temp.push_back(teamName + " have won the");
	temp.push_back("minor premiership after a hard fought season.");
	temp.push_back("Having confirmed a home qualifying final,");
	temp.push_back(teamName + " will be looking to");
	temp.push_back("convert this into the main premiership come");
	temp.push_back("grand final day.");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generatePremiershipArticle(string teamName)
{
	vector<string> temp;
	temp.push_back(teamName + " have won the");
	temp.push_back("premiership after a hard fought grand final.");
	temp.push_back("The CEO of " + teamName);
	temp.push_back("has announced a 70% discount in the merch store");
	temp.push_back("as a celebration of this achievement.");
	temp.push_back(" ");
	temp.push_back("Congratulations " + teamName + "!");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateOffContractTradeArticle(string teamName, string newPlayer, string oldPlayer)
{
	vector<string> temp;
	int pay = (rand() % 9) + 1;
	temp.push_back(teamName + " have boosted their squad");
	temp.push_back("after the signing of the off contract " + newPlayer + ".");
	temp.push_back("Unfortunately this signing also means that");
	temp.push_back(teamName + " have let go of " + oldPlayer + ".");
	temp.push_back(oldPlayer + " is now currently looking for a new club");
	temp.push_back("Sources tell us that " + newPlayer + " has");
	temp.push_back("been signed for $" +to_string(pay) + "00k/year");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateTradeArticle(string teamName1, string teamName2, string Player1, string Player2)
{
	vector<string> temp;
	temp.push_back(teamName1 + " & " + teamName2);
	temp.push_back("have agreed to do a player swap!");
	temp.push_back("This trade sees " + Player1);
	temp.push_back("find a new home at the " + teamName2);
	temp.push_back("whilst " + Player2 + " will now have to adapt");
	temp.push_back("to their new role at " + teamName1 + ".");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateFeelGoodArticleSickKids(string Player1)
{
	vector<string> temp;
	temp.push_back(Player1 + " met with some young fans");
	temp.push_back("in a local hospital yesterday. Some people");
	temp.push_back("have questioned the legitimacy of their act, with some");
	temp.push_back("claiming it was to fulfill hours of community service");
	temp.push_back("after last year's parking ticket incident.");
	temp.push_back(Player1 + " has denied these claims,");
	temp.push_back("slamming their critics as 'A Bunch Of Cowards'.");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateFeelGoodArticleSavesDrowner(string Player1)
{
	vector<string> temp;
	temp.push_back(Player1 + " has been met with applause today");
	temp.push_back("after they heroically saved a local 50 year old man");
	temp.push_back("from drowning at a local beach.");
	temp.push_back("The SRL has reacted to this event by offering the man");
	temp.push_back("free tickets to the next home game.");
	temp.push_back("The man has responded by saying:");
	temp.push_back("'I appreciate " + Player1 + ", but i hate their team.'");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateFeelGoodArticleDonatesToCharity(string Player1)
{
	vector<string> temp;
	temp.push_back(Player1 + " donated $50k to a local charity");
	temp.push_back("today, and now they are challenging other SRL players");
	temp.push_back("to match the donation.");
	temp.push_back("'We all are more fortunate then others, and we need to");
	temp.push_back("use our power to make this world a better place'");
	temp.push_back("Twitter users have criticised the donation, after it was");
	temp.push_back("found that the charity organisation has strong");
	temp.push_back("anti-LGBT connections. " + Player1);
	temp.push_back("has not commented on that matter.");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateRumourArticlePlayerRelease(string Team1, string Player1)
{
	vector<string> temp;
	temp.push_back("Sources tell us that " + Team1 + " are");
	temp.push_back("considering telling " + Player1 + " to");
	temp.push_back("Find a new home immediately. This comes after rumours");
	temp.push_back(Player1 + " has already been told they're");
	temp.push_back("free to talk to other clubs. This news has already");
	temp.push_back("sparked outrage from fans on social media, especially");
	temp.push_back("those who consider " + Player1 + " to");
	temp.push_back("be a fan favourite");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateRumourArticleContractExtension(string Team1, string Player1)
{
	vector<string> temp;
	temp.push_back("Sources tell us that " + Team1 + " are");
	temp.push_back("considering extending " + Player1 + "'s");
	temp.push_back("contract by a further 3 years.");
	temp.push_back(Player1 + " has already been approached");
	temp.push_back("by other clubs, who were hoping to snatch the");
	temp.push_back("fan favourite before season's end.");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateOpinionArticlePlayerShouldSwap(string Team1, string Player1)
{
	vector<string> temp;
	temp.push_back("After having watched " + Player1 + " play");
	temp.push_back("as long as I have for " + Team1 +",");
	temp.push_back("I have come to the conclusion that their potential is");
	temp.push_back("being wasted and they would be much better off if they");
	temp.push_back("found a home elsewhere. I don't think I've ever seen a player");
	temp.push_back("player get as screwed over by their teammates in game");
	temp.push_back("as much as " + Player1 + "does");
	temp.push_back("PASS EM THE BLOODY BALL");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateOpinionArticlePlayerOfYear(string Team1, string Player1)
{
	vector<string> temp;
	temp.push_back("The fans have spoken, and they claim that the best");
	temp.push_back("player for " + Team1 + " is no other");
	temp.push_back("than " + Player1 + "!");
	temp.push_back(Player1 + "won with 70% of the vote,");
	temp.push_back("after a social media campaign from them went");
	temp.push_back("viral. Speculation is that the club is now");
	temp.push_back("considering resigning them for another 2");
	temp.push_back("years!");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateFeelBadArticleSexScandal(string Player1)
{
	vector<string> temp;
	temp.push_back(Player1 + " is currently in hot water");
	temp.push_back("after a sexting scandal arrised today");
	temp.push_back(Player1 + " has been alleged to have been");
	temp.push_back("sexting other players for the past year and a half");
	temp.push_back("When asked for a comment, all we recieved was a pic");
	temp.push_back("of their genitalia.");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateFeelBadArticlePunchUp(string Player1)
{
	vector<string> temp;
	temp.push_back(Player1 + " is currently out on bail");
	temp.push_back("after an alleged punch on at northies RSL occured");
	temp.push_back("last friday night.");
	temp.push_back("We asked " + Player1 + " for a comment,");
	temp.push_back("who only responded by threatening to 'take this outside'");
	temp.push_back("We'll have more as this story develops");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateFeelBadArticleGambling(string Player1)
{
	vector<string> temp;
	temp.push_back(Player1 + " has allegedly lost over $30k");
	temp.push_back("at the pokies last night after a long bender.");
	temp.push_back("When reached out for a comment, " + Player1);
	temp.push_back("responded by pushing us aside, and claiming that we were");
	temp.push_back("'bringing bad luck to the machine'.");
	temp.push_back("We'll have more as this story develops");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateArticleDropControversialPlayer(string Team1, string Player1, int team1, int player1)
{
	vector<string> temp;
	temp.push_back("After a recent controversy, " + Team1);
	temp.push_back("have decided to drop " + Player1 + " from");
	temp.push_back("their team, and have released them from their contract.");
	temp.push_back("It is currently unknown who will be replacing them");
	temp.push_back("on the starting line-up, however it is confirmed ");
	temp.push_back("that " + Team1 + " already have a replacement ready.");
	temp.push_back("We'll have more as this story develops");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateArticleWalksOutOnClub(string Team1, string Player1, int team1, int player1)
{
	vector<string> temp;
	temp.push_back("After issues with recent contract negotiations, ");
	temp.push_back(Player1 + " has walked from the ");
	temp.push_back(Team1 + ", who in return have released them");
	temp.push_back("from the team, and are threatening legal action");
	temp.push_back("to get them barred from the SRL for the remainder");
	temp.push_back("of the original contract.");
	temp.push_back("It is currently unsure who will be replacing");
	temp.push_back(Player1 + " at " + Team1 + ".");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateRumourArticlePlayerUnrest(string Team1)
{
	vector<string> temp;
	temp.push_back("It seems that the coach of " + Team1);
	temp.push_back("has lost the dressing room after bombshell");
	temp.push_back("allegations arose today that 5 key players are");
	temp.push_back("considering swapping to rival clubs as soon as possible.");
	temp.push_back(Team1 + " has denied these allegations,");
	temp.push_back("jokingly adding that the only problem at the club is");
	temp.push_back("the lack of chairs in the ground.");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateRumourArticlePayCut(string Team1, string Player1)
{
	vector<string> temp;
	int pay = (rand() % 9) + 1;
	temp.push_back(Player1 + " has reportedly been told that");
	temp.push_back("if they want to stay at " + Team1 + ",");
	temp.push_back("they must be willing to take a $" + to_string(pay) + "00k/year" );
	temp.push_back("pay cut, or they won't re-sign them.");
	temp.push_back("This is the latest development in what has been a");
	temp.push_back("pretty ugly contract drama between the player and");
	temp.push_back("their club. It is expected that " + Player1);
	if (pay < 3)
	{
		temp.push_back("will accept the pay cut.");
	}
	else
	{
		temp.push_back("will decline the offer and look elsewhere.");
	}
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateRumourArticleRetirement(string Team1, string Player1)
{
	vector<string> temp;
	temp.push_back("Sources tell us that " + Player1 + " will");
	temp.push_back("be finishing their career at " + Team1 + ",");
	temp.push_back("with retirement potentially coming at the end of the season.");
	temp.push_back("The retirement is expected to be announced anywhere between");
	temp.push_back("tomorrow, and the near future.");
	temp.push_back(Player1 + " did not respond when we approached them");
	temp.push_back("for a comment.");
	return temp;
}

vector<string> SRLNewsStoryGenerator::generateFeelGoodArticleCharityEvent(string Player1, string Player2)
{
	vector<string> temp;
	temp.push_back(Player1 + " & " + Player2 + " have");
	temp.push_back("today put their SRL rivalry aside to host a charity event");
	temp.push_back("to help raise money for SYDE Disease awareness.");
	temp.push_back("The event was hosted in East Kylzebrek, & saw the two");
	temp.push_back("players coach teams of kids play touch footy games,");
	temp.push_back("some of those kids which are inflicted with the disease themselves.");
	temp.push_back(Player2 + ": 'Yeah it's a good cause'");
	return temp;
}