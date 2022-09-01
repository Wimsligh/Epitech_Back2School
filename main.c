#include "game.h"  // On inclu le fichier game.h
#include <stdio.h> // On inclu la blibliotheque stdio.h

int main() // on definit la fonction main
{
  t_game *g = game_init();

  game_loop(g);
  while (is_game_finished(g)) {
  game_loop(g); // Retourne vrai lorsque le jeux est passé par
  }
  return 0;
}

void game_loop(t_game *g) {
  int p_hand = 0;  // crée la variable p_hand comme valeur 0
  int somme = 0; // crée la variable somme comme valeur 0

  print_player_coins(g->player); // afficher le nombre de jetons du joueur
  broker_new_hand(g); // le croupier pioche
  player_new_hand(g); // le joueurs pioche
  print_player_hand(g->player); // afficher la main du joueur
  broker_place_bet(g); // le croupier mise
  player_place_bet(g); // le joueurs mise
  somme = player_ask_cards(g); // Donne la valeur qu'il reste du joueur
  p_hand = sum_player_hand(g->player); // le joueur choisi la valeur de ses valets

  if ( somme >= 6 && p_hand <= 21) {
    printf("Vous avez gagné !\n");
    player_win(g); // retourne la valeur de carte
  }
  if (p_hand == 21) {
    printf("Vous avez gagné\n");
    player_jackpot(g); // Le joueur fait 21
  }
  if ( somme >= 6 && p_hand > 21) {
    printf("le croupier et de : %i; Le score et de : %i\n", g->broker, p_hand);
    printf("Vous avez gagné\n");
    player_win(g); // Le joueur gagne
  }
  if (p_hand < 21) {
    printf("Vous avez perdu\n");
  }
  if (g->player->score <= 0) {
    printf("Vous avez perdu\n");
    game_end(g); // permet d'arrêter le jeux
  }
  print_turn_results(g, p_hand); // afficher le score du croupier et du joueur
}
