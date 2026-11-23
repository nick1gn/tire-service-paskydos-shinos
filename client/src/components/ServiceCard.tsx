import type { TireService } from "../types";

export function ServiceCard({ service }: { service: TireService }) {
  return (
    <article className="card">
      <h2>{service.title}</h2>
      <p>
        Стоимость: {service.price} руб. · Длительность: {service.durationMinutes} мин
      </p>
      <p>
        Свободно мест: {service.slotsAvailable} из {service.slotsTotal}
      </p>
    </article>
  );
}