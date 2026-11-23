import { ServiceCard } from "./components/ServiceCard";
import type { TireService } from "./types";

const services: TireService[] = [
  {
    id: "srv-1",
    title: "УСЛУГА",
    price: 100,
    durationMinutes: 60,
    slotsTotal: 1,
    slotsAvailable: 1,
  },
  {
    id: "srv-2",
    title: "УСЛУГА",
    price: 100,
    durationMinutes: 60,
    slotsTotal: 1,
    slotsAvailable: 1,
  },
  {
    id: "srv-3",
    title: "УСЛУГА",
    price: 100,
    durationMinutes: 60,
    slotsTotal: 1,
    slotsAvailable: 1,
  },
  {
    id: "srv-4",
    title: "УСЛУГА",
    price: 100,
    durationMinutes: 60,
    slotsTotal: 1,
    slotsAvailable: 1,
  },
  {
    id: "srv-5",
    title: "УСЛУГА",
    price: 100,
    durationMinutes: 60,
    slotsTotal: 1,
    slotsAvailable: 1,
  },
];

export default function App() {
  return (
    <main className="catalog">
      <h1>Услуги шиномонтажа "Паскудос шинос"</h1>
      {services.map((service) => (
        <ServiceCard key={service.id} service={service} />
      ))}
    </main>
  );
}