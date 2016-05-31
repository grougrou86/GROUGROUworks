#include "G_inc.h"
namespace ONIGIRIX_GUI {
	bool Rectangle_clip::isin(Mesure nx, Mesure ny, int rel_W, int rel_H, Rectangle_clip default_clip) {
		Rectangle_clip work = remove_default(*this, default_clip);
		return work.x.value.totalPX(rel_W) <= nx.totalPX(rel_W) && work.x.value.totalPX(rel_W) + work.w.value.totalPX(rel_W) >= nx.totalPX(rel_W) && work.y.value.totalPX(rel_H) <= ny.totalPX(rel_H) && work.y.value.totalPX(rel_H) + work.h.value.totalPX(rel_H) >= ny.totalPX(rel_H);
	}

	bool Rectangle_clip::isinx(Mesure nx, int rel_W, Rectangle_clip default_clip) {
		Rectangle_clip work = remove_default(*this, default_clip);
		return work.x.value.totalPX(rel_W) <= nx.totalPX(rel_W) && work.x.value.totalPX(rel_W) + work.w.value.totalPX(rel_W) >= nx.totalPX(rel_W);
	}
	bool Rectangle_clip::isiny(Mesure ny, int rel_H, Rectangle_clip default_clip) {
		Rectangle_clip work = remove_default(*this, default_clip);
		return work.y.value.totalPX(rel_H) <= ny.totalPX(rel_H) && work.y.value.totalPX(rel_H) + work.h.value.totalPX(rel_H) >= ny.totalPX(rel_H);
	}
	Rectangle_clip remove_default(Rectangle_clip clips, Rectangle_clip default_clip) {
		if (clips.x.is_auto) { clips.x.is_auto = false; clips.x.value = default_clip.x.value; }
		if (clips.y.is_auto) { clips.y.is_auto = false; clips.y.value = default_clip.y.value; }
		if (clips.w.is_auto) { clips.w.is_auto = false; clips.w.value = default_clip.w.value; }
		if (clips.h.is_auto) { clips.h.is_auto = false; clips.h.value = default_clip.h.value; }
		return clips;
	}
	Rectangle_clip intersection(std::vector<Rectangle_clip> const& clips, int rel_W, int rel_H, const Rectangle_clip const& default_clip) {
		if (clips.size() != 0) {
			Rectangle_clip retour = clips[0];
			if (clips.size() > 1) {
				for (size_t j = 1; j < clips.size(); j++) {
					retour = intersection(retour, clips[j], rel_W, rel_H, default_clip);
					if (retour.vide)return retour;
				}
			}
			return retour;
		}
		Rectangle_clip retour(Mesure(0, 0), Mesure(0, 0), Mesure(0, 0), Mesure(0, 0));
		retour.vide = true;
		return retour;
	}
	Rectangle_clip intersection(std::vector<Rectangle_clip*> const& clips, int rel_W, int rel_H, Rectangle_clip const& default_clip) {
		if (clips.size() != 0) {
			Rectangle_clip retour = *clips[0];
			if (clips.size() > 1) {
				for (size_t j = 1; j < clips.size(); j++) {
					retour = intersection(retour, *clips[j], rel_W, rel_H, default_clip);
					if (retour.vide)return retour;
				}
			}
			return retour;
		}
		Rectangle_clip retour(Mesure(0, 0), Mesure(0, 0), Mesure(0, 0), Mesure(0, 0));
		retour.vide = true;
		return retour;
	}
	Rectangle_clip intersection(Rectangle_clip clip1, Rectangle_clip clip2, int rel_W, int rel_H, Rectangle_clip const& default_clip) {

		if (clip1.vide)return clip1;
		if (clip2.vide)return clip2;

		clip1 = remove_default(clip1, default_clip);
		clip2 = remove_default(clip2, default_clip);

		Rectangle_clip retour(clip1);

		if (clip1.isinx(clip2.x.value, rel_W, default_clip)) { retour.x = clip2.x; }
		if (clip1.isiny(clip2.y.value, rel_H, default_clip)) { retour.y = clip2.y; }
		if (clip1.isinx(clip2.x.value + clip2.w.value, rel_W, default_clip)) { retour.w = clip2.x.value - retour.x.value + clip2.w.value; }
		else { retour.w = clip1.x.value - retour.x.value + clip1.w.value; }
		if (clip1.isiny(clip2.y.value + clip2.h.value, rel_H, default_clip)) { retour.h = clip2.y.value - retour.y.value + clip2.h.value; }
		else { retour.h = clip1.y.value - retour.y.value + clip1.h.value; }
		if (!clip2.isin(retour.x.value, retour.y.value, rel_W, rel_H, default_clip))retour.vide = true;

		return retour;

	}
	SDL_Rect Clip2Rec(Rectangle_clip clip, int rel_W, int rel_H, Rectangle_clip const& default_clip) {
		remove_default(clip, default_clip);
		SDL_Rect retour;
		retour.x = clip.x.value.totalPX(rel_W);
		retour.w = clip.w.value.totalPX(rel_W);
		retour.y = clip.y.value.totalPX(rel_H);
		retour.h = clip.h.value.totalPX(rel_H);
		return retour;
	}
	bool operator==(Rectangle_clip const& r1, Rectangle_clip const& r2) {

		return ((r1.vide&&r2.vide) || ((!r1.vide) && (!r2.vide))) && r1.x == r2.x&&r1.y == r2.y&&r1.w == r2.w&&r1.h == r2.h;

	}
	inline const bool isinx(SDL_Rect& r1, int r2) {
		return r2 >= r1.x&&r2 <= r1.x + r1.w;
	}
	inline const bool isiny(SDL_Rect& r1, int r2) {
		return r2 >= r1.y&&r2 <= r1.y + r1.h;
	}
	SDL_Rect intersection(SDL_Rect& r1, SDL_Rect& r2) {

		SDL_Rect retour = r1;

		if (isinx(r1, r2.x)) { retour.x = r2.x; }
		if (isiny(r1, r2.y)) { retour.y = r2.y; }
		if (isinx(r1, r2.x + r2.w)) { retour.w = r2.x - retour.x + r2.w; }
		else { retour.w = r1.x - retour.x + r1.w; }
		if (isiny(r1, r2.y + r2.h)) { retour.h = r2.y - retour.y + r2.h; }
		else { retour.h = r1.y - retour.y + r1.h; }
		if (!isinx(r2, retour.x) || !isiny(r2, retour.y)) { retour.w = 0; retour.h = 0; }

		return retour;

	}
}
